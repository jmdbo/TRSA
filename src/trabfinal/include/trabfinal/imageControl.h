#ifndef _IMAGECONTROL_H_
#define _IMAGECONTROL_H_

#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include <sensor_msgs/Image.h>
#include <std_msgs/Int8.h>
#include <std_msgs/Float64.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <image_transport/image_transport.h>
#include <geometry_msgs/Twist.h>
#include <trabfinal/imagePosUAV.h>
#include <sensor_msgs/Imu.h>





class imageControl{
public:

	imageControl();
	~imageControl(){};

	void run();

private:

	ros::NodeHandle nh;
	cv_bridge::CvImagePtr cvImagePtr1;
	image_transport::Subscriber imageSubRaw;
	ros::Publisher pub;
	geometry_msgs::Twist gmt;
	int controlImgCtrl, controlImgCtrl2, turnControl;
	float focalLength;
	float altitudeControl, angleControl;
	int xMaxImgCtrl, xMinImgCtrl, yMaxImgCtrl, yMinImgCtrl, xImgCtrl, yImgCtrl, xCenterUAVImgCtrl, yCenterUAVImgCtrl, xCenterHELIPADImgCtrl, yCenterHELIPADImgCtrl;
	void imageClbkRaw ( const sensor_msgs::ImageConstPtr& msg);
};
#endif
