#include "ros/ros.h"
#include "t8_package/laser_2_cloud.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "LaserScanToPointCloud");
  ros::NodeHandle n;
  LaserScan_2_PointCloud ls2pc(n);
  ros::spin();
  return 0;
}
