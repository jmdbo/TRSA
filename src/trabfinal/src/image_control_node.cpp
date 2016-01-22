#include <ros/ros.h>
#include "trabfinal/imageControl.h"

int main(int argc, char** argv){

	ros::init(argc, argv, "imgController");
	imageControl imController;
	imController.run();
	return EXIT_SUCCESS;

};
