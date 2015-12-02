#ifndef _IMAGEREADER_H_
#define _IMAGEREADER_H_

#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include <sensor_msgs/Image.h>
#include <std_msgs/Int8.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <image_transport/image_transport.h>

#include "t8_package/thermal_msg.h"




class imageReader{
public:

	imageReader();
	~imageReader(){};

	void run();

private:

	ros::NodeHandle nh;
	cv_bridge::CvImagePtr cvImagePtr1;
	cv_bridge::CvImagePtr cvImagePtr2;
	cv_bridge::CvImagePtr cvImagePtr3;
	image_transport::Subscriber imageSubRaw;
	image_transport::Subscriber imageSubRect;
	image_transport::Subscriber imageSubThermalRaw;
	ros::Publisher pub;
	cv::Mat grayImage, grayImageGauss;
	cv_bridge::CvImage out_msg;
	sensor_msgs::Image ros_image;
	cv::Size m_size;


	int find_cup(int *p, int size);
	void projections(cv::Mat img, int type, int *v);
	int img_mean(cv::Mat img);
	void imageClbkRaw ( const sensor_msgs::ImageConstPtr& msg);
	void imageClbkRect ( const sensor_msgs::ImageConstPtr& msg);
	void imageClbkThermalRaw ( const sensor_msgs::ImageConstPtr& msg);

};
#endif
