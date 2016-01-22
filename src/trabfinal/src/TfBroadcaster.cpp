#include <ros/ros.h>
#include "trabfinal/TfBroadcaster.h"

TfBroadcaster::TfBroadcaster()
{
  sub = node.subscribe("/kelp/uav/laser_scan/joint_state", 10, &TfBroadcaster::tfCallback, this);
}

void TfBroadcaster::tfCallback(const sensor_msgs::JointState::ConstPtr& msg)
{
  static tf::TransformBroadcaster brdcstr;
  tf::Transform transform;
  transform.setOrigin( tf::Vector3(0.0 , 0.0, 0.0));
  tf::Quaternion q;
  q.setRPY(msg->position[0], msg->position[1], msg->position[2]);
  transform.setRotation(q);
  brdcstr.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "hokuyo_joint_frame", "hokuyo_frame"));
  ROS_DEBUG("Broadcasting TF hokuyo_frame");
}

void TfBroadcaster::run()
{
    ros::spin();
}
