#include <ros/ros.h>
#include "trabfinal/gpsControl.h"

gpsControl::gpsControl()
{
	gpsSubHelipad = nh.subscribe("/kelp/helipad/gps", 1, &gpsControl::gpsCallbackHelipad, this);
	gpsSubUav = nh.subscribe("/kelp/uav/gps", 1, &gpsControl::gpsCallbackUav, this);
	gpsSubUavOrientation = nh.subscribe("/kelp/uav/imu", 1, &gpsControl::gpsCallbackUavOrientation, this);
	gpsPub = nh.advertise<geometry_msgs::Twist>("/kelp/robot_control", 1);
	pubControl = nh.advertise<trabfinal::controlUAV>("/controlUAV", 1);
}

void gpsControl::gpsCallbackHelipad ( const sensor_msgs::NavSatFix& msgHelipad)
{
	//-1      # unable to fix position
	//0  unaugmented fix
	//1        # with satellite-based augmentation
	//2        # with ground-based augmentation
	HELIPADStatus = msgHelipad.status.status;
	if(HELIPADStatus < 0){
		ROS_INFO("Problems with the HELIPAD GPS\n");
	}
	else
	latitudeHELIPAD = msgHelipad.latitude;
	latitudeHELIPAD = roundf(latitudeHELIPAD*100000)/100000;
	longitudeHELIPAD = msgHelipad.longitude;
	longitudeHELIPAD = roundf(longitudeHELIPAD*100000)/100000;
	altitudeHELIPAD = msgHelipad.altitude;
}


void gpsControl::gpsCallbackUav ( const sensor_msgs::NavSatFix& msgUav)
{
	//-1      # unable to fix position
	//0  unaugmented fix
	//1        # with satellite-based augmentation
	//2        # with ground-based augmentation
	UAVStatus = msgUav.status.status;
	if(UAVStatus < 0){
		ROS_INFO("Problems with the UAV GPS\n");
	}
	else
	latitudeUAV= msgUav.latitude; //Positive is north of equator; negative is south
	latitudeUAV = roundf(latitudeUAV*100000)/100000;
	longitudeUAV = msgUav.longitude;//Positive is east of prime meridian; negative is west
	longitudeUAV = roundf(longitudeUAV*100000)/100000;
	if(!firstTime){
		altitudeUAV = msgUav.altitude;//Altitude [m]. Positive is above the WGS 84 ellipsoid
		fAltitudeUAV = altitudeUAV;
		msg.altitude = altitudeUAV;
		msg.angle = w;
		pubControl.publish(msg);
		firstTime = true;
	}
	else{
		altitudeUAV = msgUav.altitude;//Altitude [m]. Positive is above the WGS 84 ellipsoid
		msg.altitude = altitudeUAV;
		msg.angle = w;
		pubControl.publish(msg);
	}

	if(altitudeUAV > altitudeHELIPAD) {
		if(latitudeUAV > latitudeHELIPAD) {
			gmt2.linear.x = -1; //speed value m/s
			gpsPub.publish(gmt2);
		}
		else if( latitudeUAV < latitudeHELIPAD) {
			gmt2.linear.x = 1; //speed value m/s
			gpsPub.publish(gmt2);
		}
		else if(latitudeUAV == latitudeHELIPAD) {
			gmt2.linear.x = 0; //speed value m/s
			gpsPub.publish(gmt2);
			if(longitudeUAV > longitudeHELIPAD) {
				if(w >= 0.755000 && w < 0.760000){
					control = 1;
				}
				else {
					gmt2.angular.z = 1;
				}
				if(control == 1) {
					gmt2.angular.z = 0;
					gmt2.linear.x = 0.5;
					gpsPub.publish(gmt2);
				}
			}
			else if(longitudeUAV < longitudeHELIPAD) {
				if( w >= 0.755000 && w < 0.760000){
					control2 = 1;
				}
				else {
					gmt2.angular.z = 0.25;
				}
				if(control2 == 1) {
					gmt2.angular.z = 0;
					gmt2.linear.x = -0.5;
					gpsPub.publish(gmt2);
				}
			}
			else if(longitudeUAV == longitudeHELIPAD) {
				gmt2.angular.z = 0;
				gmt2.linear.x = 0; //speed value m/s
				control = 0;
				control2 = 0;
				gpsPub.publish(gmt2);

				if(altitudeUAV > fAltitudeUAV / 2){
					gmt2.linear.z = -0.5; //speed value m/s
					gpsPub.publish(gmt2);
				}
				else if(altitudeUAV <= fAltitudeUAV / 2 && altitudeUAV > fAltitudeUAV / 4) {
					gmt2.linear.z = -0.35; //speed value m/s
					gpsPub.publish(gmt2);
				}
				else if(altitudeUAV <= fAltitudeUAV / 4 && altitudeUAV > fAltitudeUAV / 8) {
					gmt2.linear.z = -0.25; //speed value m/s
					gpsPub.publish(gmt2);
				}
				else if(altitudeUAV <= fAltitudeUAV / 8 && altitudeUAV > fAltitudeUAV / 16) {
					gmt2.linear.z = -0.15; //speed value m/s
					gpsPub.publish(gmt2);
				}
				else if (altitudeUAV <= fAltitudeUAV / 16) {
					gmt2.linear.z = -0.05; //speed value m/s
					gpsPub.publish(gmt2);
				}
			}
		}
	}
	else if(altitudeUAV < altitudeHELIPAD) {
		if(longitudeUAV > longitudeHELIPAD && longitudeUAV < longitudeHELIPAD + 0.2 * longitudeHELIPAD || longitudeUAV < longitudeHELIPAD && longitudeUAV > longitudeHELIPAD - 0.2*longitudeHELIPAD || latitudeUAV > latitudeHELIPAD && latitudeUAV < latitudeHELIPAD + 0.2 * latitudeHELIPAD || latitudeUAV < latitudeHELIPAD && latitudeUAV > latitudeHELIPAD - 0.2 * latitudeHELIPAD){
			if(altitudeUAV < fAltitudeUAV / 2){
				gmt2.linear.z = 0.5; //speed value m/s
				gpsPub.publish(gmt2);
			}
			else if(altitudeUAV >= fAltitudeUAV / 2 && altitudeUAV < fAltitudeUAV / 4) {
				gmt2.linear.z = 0.35; //speed value m/s
				gpsPub.publish(gmt2);
			}
			else if(altitudeUAV >= fAltitudeUAV / 4 && altitudeUAV < fAltitudeUAV / 8) {
				gmt2.linear.z = 0.25; //speed value m/s
				gpsPub.publish(gmt2);
			}
			else if(altitudeUAV >= fAltitudeUAV / 8 && altitudeUAV < fAltitudeUAV / 16) {
				gmt2.linear.z = 0.15; //speed value m/s
				gpsPub.publish(gmt2);
			}
			else if(altitudeUAV >= fAltitudeUAV / 16){
				gmt2.linear.z = 0.05; //speed value m/s
				gpsPub.publish(gmt2);
			}
		}
		else {
			gmt2.linear.x = 1; //speed value m/s
			gpsPub.publish(gmt2);
		}
	}
	else  {
		gmt2.linear.z = 0; //speed value m/s
		firstTime = false;
		gpsPub.publish(gmt2);
	}
}
void gpsControl::gpsCallbackUavOrientation ( const sensor_msgs::Imu& msgUavOrientation){
	x = msgUavOrientation.orientation.x;
	y = msgUavOrientation.orientation.y;
	z = msgUavOrientation.orientation.z;
	w = msgUavOrientation.orientation.w;
}


void gpsControl::run(){
	ros::spin();
}
