#include <ros/ros.h>
#include "t8_package/imageReader.h"

imageReader::imageReader()
{
	image_transport::ImageTransport it(nh);
	imageSubRaw = it.subscribe("/camera/image_raw", 1, &imageReader::imageClbkRaw, this);
	imageSubRect = it.subscribe("/camera/image_rect", 1, &imageReader::imageClbkRect, this);
	imageSubThermalRaw = it.subscribe("/thermal_camera/image_raw", 1, &imageReader::imageClbkThermalRaw, this);
	pub = nh.advertise<t8_package::thermal_msg>("/thermal_label", 1);
}

int imageReader::find_cup(int *p, int size){
	int sum=0,max=0,at=0,i;
	for( i=0; i<size/3; i++){
		sum += p[i];
	}
	max=sum;
	at=1;

	for(sum=0; i<(size/3)*2; i++){
		sum += p[i];
	}
	if(sum > max){
		max=sum;
		at=2;
	}

	for(sum=0; i<size; i++){
		sum += p[i];
	}
	if(sum > max){
		at=3;
	}

	return at;
}

void imageReader::projections(cv::Mat img, int type, int *v){

	for(int y=0;y<img.rows;y++)
	for(int x=0;x<img.cols;x++)
	{
		uchar color = img.at<uchar>(cv::Point(x,y));
		if((color > 127)-type){
			v[x]++;
			ROS_INFO("X - %d", x);
			ROS_INFO("Y - %d", y);
		}
	}
}

int imageReader::img_mean(cv::Mat img){
	int mean=0;
	for(int y=0;y<img.rows;y++)
	for(int x=0;x<img.cols;x++)
	{
		uchar color = img.at<uchar>(cv::Point(x,y));
		mean+=color;
	}
	return mean / (img.rows*img.cols);
}

void imageReader::imageClbkRaw ( const sensor_msgs::ImageConstPtr& msg)
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


	//cv::imshow( "Image Reader Raw", cvImagePtr1->image ); // opens a named window to display the image
	cv::waitKey(1);
}

void imageReader::imageClbkRect ( const sensor_msgs::ImageConstPtr& msg)
{

	try
	{
		// toCvCopy method copies the image data and returns a mutable CvImage
		cvImagePtr2 = cv_bridge::toCvCopy( msg );
		// toCvShare method shares the image data, returning a const CvImage
		// cv_bridge::CvImageConstPtr cvImagePtr = cv_bridge::toCvShare( rosImage );
	} catch (cv_bridge::Exception &e) {
		ROS_ERROR( "cv_bridge exception: %s", e.what() );
	}
	//cv::imshow( "Image Reader Rect", cvImagePtr2->image ); // opens a named window to display the image

}

void imageReader::imageClbkThermalRaw ( const sensor_msgs::ImageConstPtr& msg)
{

	try
	{
		// toCvCopy method copies the image data and returns a mutable CvImage
		cvImagePtr3 = cv_bridge::toCvCopy( msg );
		// toCvShare method shares the image data, returning a const CvImage
		// cv_bridge::CvImageConstPtr cvImagePtr = cv_bridge::toCvShare( rosImage );
	} catch (cv_bridge::Exception &e) {
		ROS_ERROR( "cv_bridge exception: %s", e.what() );
	}

		//RGB image to gray
		cv::cvtColor(cvImagePtr3->image, cvImagePtr3->image, CV_BGR2GRAY);
		// cv::imshow( "Raw", cvImagePtr3->image);

		//BINARY..
		cv::threshold(cvImagePtr3->image, cvImagePtr3->image, 155, 255, CV_THRESH_BINARY );
		//cv::Mat element = cv::getStructuringElement( 0,cv::Size( 4, 4 ),cv::Point( 2, 2 ) );
		//cv::erode( cvImagePtr3->image, cvImagePtr3->image, element );
		cv::imshow( "Otsu", cvImagePtr3->image);

		// Declaring projection vector
		int vp[cvImagePtr3->image.cols];
		for(int i=0; i< cvImagePtr3->image.cols; i++)
		vp[i]=0;

		/*
		* If m > 127, then image is too white and temperature is COLD! (sending 1 search for black pixels in the image)
		* HOT otherwise
		*/
		t8_package::thermal_msg msgOut;
		if(img_mean(cvImagePtr3->image) > 127 ){
			projections(cvImagePtr3->image,1,vp);
			//COLD
			ROS_INFO("Found COLD\n");
			msgOut.temp = 0;
		}
		else{
			projections(cvImagePtr3->image,0,vp);
			//HOT
			ROS_INFO("Found HOT\n");
			msgOut.temp = 1;
		}

		msgOut.id = find_cup(vp,cvImagePtr3->image.cols);
		ROS_INFO("Found at %d\n",msgOut.id);
		pub.publish(msgOut);
		cv::waitKey(1);





	cv::waitKey(1);
}

void imageReader::run(){

	ros::spin();

}
