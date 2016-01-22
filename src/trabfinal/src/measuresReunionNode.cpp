#include <ros/ros.h>
#include "trabfinal/measuresReunion.h"

int main(int argc, char** argv){

	ros::init(argc, argv, "measuresReunion_node");
	measuresReunion mReunion;
	mReunion.run();
	return EXIT_SUCCESS;

};
