#include <ros/ros.h>
#include "trabfinal/GpsControl.h"

GpsControl::GpsControl()
{
	GpsPub = nh.advertise<trabfinal::gpsXY>("/autoland/robotPosition", 1);
	GpsSubHelipad = nh.subscribe("/kelp/helipad/gps", 1, &GpsControl::gpsCallbackHelipad, this);
	GpsSubUav = nh.subscribe("/kelp/uav/gps", 1, &GpsControl::gpsCallbackUav, this);
}

void GpsControl::gpsCallbackHelipad ( const sensor_msgs::NavSatFix& msgHelipad)
{
	HELIPADStatus = msgHelipad.status.status;
	if(HELIPADStatus < 0){
		ROS_INFO("Problems with the HELIPAD GPS\n");
	}
	else{
		latitudeHELIPAD = msgHelipad.latitude;
		longitudeHELIPAD = msgHelipad.longitude;
		altitudeHELIPAD = msgHelipad.altitude;
	}
}

void GpsControl::gpsCallbackUav( const sensor_msgs::NavSatFix& msgUAV)
{

	UAVStatus = msgUAV.status.status;
	if(UAVStatus < 0){
		ROS_INFO("Problems with the UAV GPS\n");
	}
	else{
		latitudeUAV = msgUAV.latitude;
		longitudeUAV = msgUAV.longitude;
		altitudeUAV = msgUAV.altitude;
		convertLATLON2Meters(latitudeUAV, longitudeUAV, latitudeHELIPAD, longitudeHELIPAD, &uavX, &uavY);
		msg.x = uavX;
		msg.y = uavY;
		msg.z = altitudeUAV;
		GpsPub.publish(msg);
	}
}

void GpsControl::convertLATLON2Meters(float latUAV, float lonUAV, float latHELIPAD, float lonHELIPAD, float *x, float *y)
{
	float dLat = latitudeUAV - latitudeHELIPAD;
	float dLon = longitudeUAV - longitudeHELIPAD;
	float latitudeCircuference = 40075160 * cos(latitudeHELIPAD * 3.14 / 180);
	*x = dLon * latitudeCircuference / 360;
	*y = dLat * 40008000 / 360;
}

void GpsControl::run()
{
	ros::spin();
}
