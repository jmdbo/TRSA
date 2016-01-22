#ifndef _TFBROADCASTER_H_
#define _TFBROADCASTER_H_

#include <ros/ros.h>
#include <ros/package.h>

#include <tf/transform_broadcaster.h>
#include <sensor_msgs/JointState.h>

class TfBroadcaster
{
  public:
     TfBroadcaster();
     virtual ~TfBroadcaster(){};

     void run();

   private:
     ros::NodeHandle node;
     ros::Subscriber sub;

     void tfCallback(const sensor_msgs::JointState::ConstPtr& msg);

};


#endif
