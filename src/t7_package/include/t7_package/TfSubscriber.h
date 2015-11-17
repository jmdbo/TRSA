#ifndef _TFSUBSCRIBER_H_
#define _TFSUBSCRIBER_H_

#include <ros/ros.h>
#include <tf/transform_listener.h>

class TfSubscriber
{
  public:
     TfSubscriber();
     virtual ~TfSubscriber(){};

     void run();

   private:
     ros::NodeHandle node;
     tf::TransformListener listener;

};


#endif
