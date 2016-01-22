#include <ros/ros.h>
#include "trabfinal/measuresReunion.h"

measuresReunion::measuresReunion()
{
	//----------------------------GPS------------------
	gpsSubHelipad = nh.subscribe("/kelp/helipad/gps", 1, &measuresReunion::gpsCallbackHelipad, this);
	gpsSubUav = nh.subscribe("/kelp/uav/gps", 1, &measuresReunion::gpsCallbackUav, this);
	gpsSubUavOrientation = nh.subscribe("/kelp/uav/imu", 1, &measuresReunion::gpsCallbackUavOrientation, this);
	R = 6371; //Earth Radius
	pi = 3.14159265359;
	//-------------------------IMAGE-----------------------------
	image_transport::ImageTransport it(nh);
	imageSubRaw = it.subscribe("/kelp/helipad/camera/image", 1, &measuresReunion::imageClbkRaw, this);

}

void measuresReunion::gpsCallbackHelipad ( const sensor_msgs::NavSatFix& msgHelipad)
{
	//-1      # unable to fix position
	//0  unaugmented fix
	//1        # with satellite-based augmentation
	//2        # with ground-based augmentation
	HELIPADStatus = msgHelipad.status.status;
	if(HELIPADStatus < 0){
		ROS_WARN("Problems with the HELIPAD GPS\n");
	}
	else{

		latitudeHELIPAD = pi * msgHelipad.latitude / 180;
		longitudeHELIPAD = pi * msgHelipad.longitude / 180;
		altitudeHELIPAD = msgHelipad.altitude;
		xHELIPADGPS = R * cos(latitudeHELIPAD) * cos(longitudeHELIPAD);
		yHELIPADGPS = R * cos(latitudeHELIPAD) * sin(longitudeHELIPAD);
		zHELIPADGPS = altitudeHELIPAD;
	}
}

void measuresReunion::gpsCallbackUav ( const sensor_msgs::NavSatFix& msgUav)
{
	//-1      # unable to fix position
	//0  unaugmented fix
	//1        # with satellite-based augmentation
	//2        # with ground-based augmentation
	UAVStatus = msgUav.status.status;
	if(UAVStatus < 0){
		ROS_WARN("Problems with the UAV GPS\n");
	}
	else{

		latitudeUAV = pi * msgUav.latitude / 180;
		longitudeUAV = pi * msgUav.longitude / 180;
		altitudeUAV = msgUav.altitude;

		xUAVGPS = R * cos(latitudeUAV) * cos(longitudeUAV);
		yUAVGPS = R * cos(latitudeUAV) * sin(longitudeUAV);
		zUAVGPS = altitudeUAV;
		xgpsDiff = xUAVGPS - xHELIPADGPS;
		ygpsDiff = yUAVGPS - yHELIPADGPS;
		zgpsDiff = zUAVGPS - zHELIPADGPS;
		ROS_INFO("xUAVGPS = %f, yUAVGPS = %f, zUAVGPS = %f", xUAVGPS, yUAVGPS, zUAVGPS);
		//ROS_INFO("xDiffGPS = %f , yDiffGPS = %f, zDiffGPS = %f", xgpsDiff, ygpsDiff , zgpsDiff);
	}
}

void measuresReunion::gpsCallbackUavOrientation ( const sensor_msgs::Imu& msgUavOrientation){
	x = msgUavOrientation.orientation.x;
	y = msgUavOrientation.orientation.y;
	z = msgUavOrientation.orientation.z;
	w = msgUavOrientation.orientation.w;
}



//-----------------------------IMAGE-----------------------------------------------

void measuresReunion::imageClbkRaw ( const sensor_msgs::ImageConstPtr& msg)
{

	//if(altitudeControl <= focalLength){
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
	int projectionVectorX[cvImagePtr1->image.cols];
	int projectionVectorY[cvImagePtr1->image.rows];

	for(x2 = 0; x2 < cvImagePtr1->image.cols; x2++){
		projectionVectorX[x2] = 0;
	}
	for(x2 = 0; x2 < cvImagePtr1->image.rows; x2++){
		projectionVectorY[x2] = 0;
	}

	for(int y = 0; y < cvImagePtr1->image.rows; y++){
		for(int x2 = 0; x2 < cvImagePtr1->image.cols; x2++)
		{
			uchar color = cvImagePtr1->image.at<uchar>(cv::Point(x2,y));
			if((color > 127)){
				projectionVectorX[x2]++;
				projectionVectorY[y]++;
			}
		}
	}

	int xMax = 0;
	int xMin = cvImagePtr1->image.cols;
	int yMax = 0;
	int yMin = cvImagePtr1->image.rows;

	for(x2 = 0; x2 < cvImagePtr1->image.cols; x2++){


		if(projectionVectorX[x2] >  0){
			if(xMax < x2){
				xMax = x2;
			}

			if(xMin > x2) {
				xMin = x2;
			}
		}
	}

	for(x2 = 0; x2 < cvImagePtr1->image.rows; x2++){
		if(projectionVectorY[x2] >  0){

			if(yMax < x2){
				yMax = x2;
			}

			if(yMin > x2) {
				yMin = x2;
			}
		}
	}

	xCenterUAV = (int)(((xMax - xMin) / 2) + xMin);
	yCenterUAV = (int)(((yMax - yMin) / 2) + yMin);

	//ROS_INFO("xCenterUAV = %d, yCenterUAV = %d", xCenterUAV, yCenterUAV);

	cv::circle(cvImagePtr1->image, cv::Point (xCenterUAV, yCenterUAV), 2, cv::Scalar(0,0,255), 3, 8, 0);
	cv::imshow( "HELIPAD Cam", cvImagePtr1->image);
	cv::waitKey(1);
	//	}
}
//------------------------------Laser------------------------------------------

//---------------------------COMON---------------------------------------------

void measuresReunion::run(){
	ros::spin();
}
