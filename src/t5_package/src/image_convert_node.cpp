#include <ros/ros.h>
#include "t5_package/ImageConvert.h"


int main(int argc, char **argv)
{
  ros::init( argc, argv, "image_converter" );

  ImageConvert converter;

  converter.run();

  return EXIT_SUCCESS;

}
