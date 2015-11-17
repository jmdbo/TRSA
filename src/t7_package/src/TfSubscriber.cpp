#include <ros/ros.h>
#include "t7_package/TfSubscriber.h"

TfSubscriber::TfSubscriber()
{
  ROS_INFO("TF LISTENER STARTED!");
}


void TfSubscriber::run()
{
   ros::Rate rate(10.0);
   while (node.ok()){
     tf::StampedTransform transform;
     try{
       listener.lookupTransform("map", "base_footprint", ros::Time(0), transform);
     }
     catch (tf::TransformException &ex) {
       ROS_ERROR("%s",ex.what());
       ros::Duration(1.0).sleep();
       continue;
     }
     ROS_INFO("---------------------TF VALUES-----------------------");
     ROS_INFO("\tX Value: %.8f", transform.getOrigin().x());
     ROS_INFO("\tY Value: %.8f", transform.getOrigin().y());
     ROS_INFO("\tZ Value: %.8f", transform.getOrigin().z());
     ROS_INFO("-----------------------------------------------------");
     rate.sleep();
  }
}
