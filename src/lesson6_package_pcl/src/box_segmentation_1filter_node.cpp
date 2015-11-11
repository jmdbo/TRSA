#include "ros/ros.h"
#include "lesson6_package_pcl/box_segmentation.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "BoxSegmentation");
  ros::NodeHandle n;
  Box_Segmentation bs(n);
  ros::spin();
  return 0;
}
