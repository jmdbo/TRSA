#include <ros/ros.h>
#include "trabfinal/UAVController.h"

int main(int argc, char** argv){

	ros::init(argc, argv, "UAVController");
	UAVController UAVController;
	UAVController.run();
	return EXIT_SUCCESS;

};
