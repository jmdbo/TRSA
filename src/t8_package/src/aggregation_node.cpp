#include "ros/ros.h"
#include "t8_package/aggregation.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "Aggregation");
  ros::NodeHandle n;
  Aggregation ag(n);
  ros::spin();
  return 0;
}
