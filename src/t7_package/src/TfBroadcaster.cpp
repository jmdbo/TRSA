#include <ros/ros.h>
#include "t7_package/TfBroadcaster.h"

TfBroadcaster::TfBroadcaster()
{
  sub = node.subscribe("/tripod/height", 10, &TfBroadcaster::tfCallback, this);
}

void TfBroadcaster::tfCallback(const std_msgs::Float32ConstPtr& msg)
{
  static tf::TransformBroadcaster brdcstr;
  tf::Transform transform;
  transform.setOrigin( tf::Vector3(0.0 , 0.0, msg->data));
  tf::Quaternion q;
  q.setRPY(0, 0, 0);
  transform.setRotation(q);
  brdcstr.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "base_footprint", "sensor_frame"));
}

void TfBroadcaster::run()
{
    ros::spin();
}
