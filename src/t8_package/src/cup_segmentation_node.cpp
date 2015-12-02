#include "ros/ros.h"
#include "t8_package/cup_segmentation.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "CupSegmentation");
  ros::NodeHandle n;
  Cup_Segmentation bs(n);
  ros::spin();
  return 0;
}
