#include "ros/ros.h"
#include "trabfinal/uav_segmentation.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "UAVSegmentation");
  ros::NodeHandle n;
  UAV_Segmentation bs(n);
  ros::spin();
  return 0;
}
