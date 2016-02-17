#include <ros/ros.h>
#include "trabfinal/GpsControl.h"

int main(int argc, char** argv){

	ros::init(argc, argv, "gpsController");
	GpsControl GpController;
	GpController.run();
	return EXIT_SUCCESS;

};
