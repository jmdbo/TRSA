#include <ros/ros.h>
#include "trabfinal/imageControl.h"

imageControl::imageControl()
{
	image_transport::ImageTransport it(nh);
	imageSubRaw = it.subscribe("/kelp/helipad/camera/image", 1, &imageControl::imageClbkRaw, this);
	pub = nh.advertise<trabfinal::imagePosUAV>("/autoland/imagePosUAV", 1);
}




void imageControl::imageClbkRaw ( const sensor_msgs::ImageConstPtr& msg)
{

	try
	{
		// toCvCopy method copies the image data and returns a mutable CvImage
		cvImagePtr1 = cv_bridge::toCvCopy( msg );
		// toCvShare method shares the image data, returning a const CvImage
		// cv_bridge::CvImageConstPtr cvImagePtr = cv_bridge::toCvShare( rosImage );
	} catch (cv_bridge::Exception &e) {
		ROS_ERROR( "cv_bridge exception: %s", e.what() );
	}

	//RGB image to gray
	cv::cvtColor(cvImagePtr1->image, cvImagePtr1->image, CV_BGR2GRAY);
	//BINARY..
	cv::threshold(cvImagePtr1->image, cvImagePtr1->image, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
	// Declaring projection vector
	int* projectionVectorXImgCtrl = new int[cvImagePtr1->image.cols]();
	int* projectionVectorYImgCtrl = new int[cvImagePtr1->image.rows]();

	for(yImgCtrl = 0; yImgCtrl < cvImagePtr1->image.rows; yImgCtrl++){
		for(xImgCtrl = 0; xImgCtrl < cvImagePtr1->image.cols; xImgCtrl++)
		{
			uchar colorImgCtrl = cvImagePtr1->image.at<uchar>(cv::Point(xImgCtrl,yImgCtrl));
			if((colorImgCtrl > 127)){
				projectionVectorXImgCtrl[xImgCtrl]++;
				projectionVectorYImgCtrl[yImgCtrl]++;
			}
		}
	}

	xMaxImgCtrl = 0;
	xMinImgCtrl = cvImagePtr1->image.cols;
	yMaxImgCtrl = 0;
	yMinImgCtrl = cvImagePtr1->image.rows;

	for(xImgCtrl = 0; xImgCtrl < cvImagePtr1->image.cols; xImgCtrl++){
		if(projectionVectorXImgCtrl[xImgCtrl] >  0){
			if(xMaxImgCtrl < xImgCtrl){
				xMaxImgCtrl = xImgCtrl;
			}

			if(xMinImgCtrl > xImgCtrl) {
				xMinImgCtrl = xImgCtrl;
			}
		}
	}

	for(xImgCtrl = 0; xImgCtrl < cvImagePtr1->image.rows; xImgCtrl++){
		if(projectionVectorYImgCtrl[xImgCtrl] >  0){

			if(yMaxImgCtrl < xImgCtrl){
				yMaxImgCtrl = xImgCtrl;
			}

			if(yMinImgCtrl > xImgCtrl) {
				yMinImgCtrl = xImgCtrl;
			}
		}
	}

	xCenterUAVImgCtrl = (int)(((xMaxImgCtrl - xMinImgCtrl) / 2) + xMinImgCtrl);
	yCenterUAVImgCtrl = (int)(((yMaxImgCtrl - yMinImgCtrl) / 2) + yMinImgCtrl);
	xCenterHELIPADImgCtrl = (int)( cvImagePtr1->image.cols / 2);
	yCenterHELIPADImgCtrl = (int)( cvImagePtr1->image.rows / 2);


	xCenterUAVImgCtrl = -1*(xCenterUAVImgCtrl - xCenterHELIPADImgCtrl);
	yCenterUAVImgCtrl = -1*(yCenterUAVImgCtrl - yCenterHELIPADImgCtrl);

	trabfinal::imagePosUAV imgPos;
	imgPos.xCenterUAV = xCenterUAVImgCtrl;
	imgPos.yCenterUAV = yCenterUAVImgCtrl;
	imgPos.xCenterImg = xCenterHELIPADImgCtrl;
	imgPos.yCenterImg = yCenterHELIPADImgCtrl;

	pub.publish(imgPos);


	cv::imshow( "HELIPAD Cam", cvImagePtr1->image);
	cv::waitKey(1);
	delete [] projectionVectorXImgCtrl;
	delete [] projectionVectorYImgCtrl;
}

void imageControl::run(){
	ros::spin();
}
