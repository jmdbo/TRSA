#ifndef _AGGREGATION_H_
#define _AGGREGATION_H_

#include <ros/ros.h>
#include <t8_package/thermal_msg.h>
#include <t8_package/cup_info.h>
#include <tf/transform_listener.h>

class Aggregation{
  public:

  ros::NodeHandle n_;
  ros::Subscriber thermal_sub_;
  ros::Publisher selected_cup_pub_;
  tf::TransformListener tf_listener;
  int seq;

  Aggregation(ros::NodeHandle n);
  void thermalCallback (const t8_package::thermal_msg &thermal_in);
};

#endif
