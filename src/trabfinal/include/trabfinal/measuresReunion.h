#ifndef _MEASURESREUNION_H_
#define _MEASURESREUNION_H_

#include <ros/ros.h>
#include <std_msgs/Int8.h>
#include <sensor_msgs/NavSatFix.h>
#include <sensor_msgs/NavSatStatus.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/Twist.h>
#include <math.h>
#include <trabfinal/altitudeUAV.h>
#include <opencv2/opencv.hpp>
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <image_transport/image_transport.h>





class measuresReunion{
public:

	measuresReunion();
	~measuresReunion(){};

	void run();

private:

	ros::NodeHandle nh;

	//--------------------GPS--------------------------------
	ros::Subscriber gpsSubHelipad;
	ros::Subscriber gpsSubUav;
	ros::Subscriber gpsSubUavOrientation;
	ros::Publisher pubAltitude;
	trabfinal::altitudeUAV msg;
	geometry_msgs::Twist gmt2;
	int UAVStatus;
	int HELIPADStatus;
	float latitudeUAV;
	float latitudeHELIPAD;
	float longitudeUAV;
	float longitudeHELIPAD;
	float altitudeUAV;
	float altitudeHELIPAD;
	float x;
	float y;
	float z;
	float w;
	float xUAVGPS;
	float yUAVGPS;
	float zUAVGPS;
	float xHELIPADGPS;
	float yHELIPADGPS;
	float zHELIPADGPS;
	float xgpsDiff, ygpsDiff, zgpsDiff;
	long R;
	float pi;
	void gpsCallbackHelipad( const sensor_msgs::NavSatFix& msgHelipad);
	void gpsCallbackUav( const sensor_msgs::NavSatFix& msgUav);
	void gpsCallbackUavOrientation( const sensor_msgs::Imu& msgUavOrientation);

	//------------------------IMAGE----------------------------------------

	cv_bridge::CvImagePtr cvImagePtr1;
	image_transport::Subscriber imageSubRaw;
	int img_mean(cv::Mat img);
	int id;
	void imageClbkRaw ( const sensor_msgs::ImageConstPtr& msg);
	int xCenterUAV, yCenterUAV;
	float xUAVIMAGE;
	float yUAVIMAGE;
	float zUAVIMAGE;
	float xHELIPADIMAGE;
	float yHELIPADIMAGE;
	float zHELIPADIMAGE;
	int x2; //PAra os for's
};
#endif
