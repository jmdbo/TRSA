#include <ros/ros.h>
#include "t7_package/TfSubscriber.h"


int main(int argc, char **argv)
{
  ros::init( argc, argv, "tf_subscriber" );

  TfSubscriber subscriber;

  subscriber.run();

  return EXIT_SUCCESS;

}
