#include <ros/ros.h>
#include "t8_package/aggregation.h"


Aggregation::Aggregation(ros::NodeHandle n) :
n_(n)
{
  thermal_sub_ = n_.subscribe("/thermal_label", 1000, &Aggregation::thermalCallback, this);
  selected_cup_pub_ = n_.advertise<t8_package::cup_info>("/selected_cup",1);
  seq = 0;
}

void Aggregation::thermalCallback (const t8_package::thermal_msg& thermal_in){
  t8_package::cup_info msg;

  tf::StampedTransform tfCup1;
  tf::StampedTransform tfCup2;
  tf::StampedTransform tfCup3;

  msg.Bag_name = "RICS_BAG";
  msg.Group_number = 1;
  msg.Thermal_label = thermal_in.temp;
  msg.Header.seq = seq++;

  try{
    tf_listener.lookupTransform("/base_footprint", "/cup1", ros::Time(0), tfCup1);
    tf_listener.lookupTransform("/base_footprint", "/cup2", ros::Time(0), tfCup2);
    tf_listener.lookupTransform("/base_footprint", "/cup3", ros::Time(0), tfCup3);
  } catch (tf::TransformException &ex) {
         ROS_ERROR("%s",ex.what());
         ros::Duration(1.0).sleep();
         return;
   }
  if(thermal_in.id == 1){
    msg.Object_position.x = tfCup1.getOrigin().getX();
    msg.Object_position.y = tfCup1.getOrigin().getY();
    msg.Object_position.z = tfCup1.getOrigin().getZ();
    msg.Header.stamp = tfCup1.stamp_;
  } else if (thermal_in.id == 2){
    msg.Object_position.x = tfCup2.getOrigin().getX();
    msg.Object_position.y = tfCup2.getOrigin().getY();
    msg.Object_position.z = tfCup2.getOrigin().getZ();
    msg.Header.stamp = tfCup2.stamp_;
  } else if (thermal_in.id == 3){
    msg.Object_position.x = tfCup3.getOrigin().getX();
    msg.Object_position.y = tfCup3.getOrigin().getY();
    msg.Object_position.z = tfCup3.getOrigin().getZ();
    msg.Header.stamp = tfCup3.stamp_;
  }
  selected_cup_pub_.publish(msg);


}
