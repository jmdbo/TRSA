#ifndef _GPSCONTROL_H_
#define _GPSCONTROL_H_

#include <ros/ros.h>
#include <std_msgs/Int8.h>
#include <sensor_msgs/NavSatFix.h>
#include <sensor_msgs/NavSatStatus.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/Twist.h>
#include <math.h>
#include <trabfinal/controlUAV.h>





class gpsControl{
public:

	gpsControl();
	~gpsControl(){};

	void run();

private:

	ros::NodeHandle nh;
	ros::Subscriber gpsSubHelipad;
	ros::Subscriber gpsSubUav;
	ros::Subscriber gpsSubUavOrientation;
	ros::Publisher gpsPub; //Pode não ser necessário
	ros::Publisher pubControl;
	trabfinal::controlUAV msg;
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
	float angle;
	bool firstTime;
	float fAltitudeUAV;
	int firstEnter;
	int firstEnter2;
	int control;
	int control2;

	void gpsCallbackHelipad( const sensor_msgs::NavSatFix& msgHelipad);
	void gpsCallbackUav( const sensor_msgs::NavSatFix& msgUav);
	void gpsCallbackUavOrientation( const sensor_msgs::Imu& msgUavOrientation);
};
#endif
