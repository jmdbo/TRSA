#include "ros/ros.h"
#include "trabfinal/laser_2_cloud.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "laser2Cloud");
  ros::NodeHandle n;
  LaserScan_2_PointCloud ls2pc(n);
  ls2pc.run();

  return 0;
}
