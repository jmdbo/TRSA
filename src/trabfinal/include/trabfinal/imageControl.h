#ifndef _IMAGECONTROL_H_
#define _IMAGECONTROL_H_

#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <trabfinal/imagePosUAV.h>


class imageControl{
public:

	imageControl();
	~imageControl(){};

	void run();

private:

	/* Common Variables */
	ros::NodeHandle nh;
	cv_bridge::CvImagePtr cvImagePtr1; //Pointer to image
	int xMaxImgCtrl, xMinImgCtrl, yMaxImgCtrl, yMinImgCtrl, xImgCtrl, yImgCtrl; //Stores the projection vectors indexes where the object is located
	int xCenterUAVImgCtrl, yCenterUAVImgCtrl, xCenterHELIPADImgCtrl, yCenterHELIPADImgCtrl;  //Stores the values of the x and y values of the center of the Uav and of the Helipad

	/* Message Publishers & Subscribers */
	image_transport::Subscriber imageSubRaw;
	ros::Publisher pub;

	/* Received Messages Callbacks */
	void imageClbkRaw ( const sensor_msgs::ImageConstPtr& msg);
};
#endif
