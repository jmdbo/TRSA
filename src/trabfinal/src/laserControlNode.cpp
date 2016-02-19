#include <ros/ros.h>
#include "trabfinal/laserControl.h"

int main(int argc, char** argv){

	ros::init(argc, argv, "laserController");
	laserControl lController;
	lController.run();
	return EXIT_SUCCESS;

};
