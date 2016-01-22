#include <ros/ros.h>
#include "trabfinal/gpsControl.h"

int main(int argc, char** argv){

	ros::init(argc, argv, "gpsController");
	gpsControl gpController;
	gpController.run();
	return EXIT_SUCCESS;

};
