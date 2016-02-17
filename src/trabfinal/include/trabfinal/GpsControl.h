#ifndef _GPSCONTROL_H_
#define _GPSCONTROL_H_

#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>
#include <sensor_msgs/NavSatStatus.h>
#include <sensor_msgs/Imu.h>
#include <trabfinal/gpsXY.h>



class GpsControl{
public:

	GpsControl();
	~GpsControl(){};

	void run();

private:

	/* Common Variables */
	ros::NodeHandle nh;
	int UAVStatus, HELIPADStatus; // Stores the status of the Uav and Helipad GPS : -1 -> unable to fix position, 0 -> unaugmented fix, 1 -> with satellite-based augmentation, 2 -> with ground-based augmentation
	float latitudeUAV, latitudeHELIPAD,longitudeUAV, longitudeHELIPAD, altitudeUAV, altitudeHELIPAD; //Stores the GPS Values for Uav and Helipad
	float uavX, uavY; //Stores the converted values of the Uav latitude and longitude
	trabfinal::gpsXY msg; //Message to the Controller

	/* Message Publishers & Subscribers */
	ros::Publisher GpsPub;
	ros::Subscriber GpsSubHelipad;
	ros::Subscriber GpsSubUav;

	/* Received Messages Callbacks */
	void gpsCallbackHelipad( const sensor_msgs::NavSatFix& msgHelipad);
	void gpsCallbackUav( const sensor_msgs::NavSatFix& msgUav);

	/* Converter from Latitude and Longitude Degrees to Latitude and Longitude Meters */
	void convertLATLON2Meters(float latUAV, float lonUAV, float latHELIPAD, float lonHELIPAD, float *x, float *y);
};
#endif
