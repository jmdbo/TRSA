#ifndef _TFBROADCASTER_H_
#define _TFBROADCASTER_H_

#include <ros/ros.h>
#include <ros/package.h>

#include <tf/transform_broadcaster.h>
#include <std_msgs/Float32.h>

class TfBroadcaster
{
  public:
     TfBroadcaster();
     virtual ~TfBroadcaster(){};

     void run();

   private:
     ros::NodeHandle node;
     ros::Subscriber sub;

     void tfCallback(const std_msgs::Float32ConstPtr& msg);

};


#endif
