#include <ros/ros.h>
#include "t8_package/imageReader.h"

int main(int argc, char** argv){

	ros::init(argc, argv, "image_reader_copos");
	imageReader imReader;
	imReader.run();
	return EXIT_SUCCESS;

};
