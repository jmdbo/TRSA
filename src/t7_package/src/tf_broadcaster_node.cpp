#include <ros/ros.h>
#include "t7_package/TfBroadcaster.h"


int main(int argc, char **argv)
{
  ros::init( argc, argv, "tf_broadcaster" );

  TfBroadcaster broadcaster;

  broadcaster.run();

  return EXIT_SUCCESS;

}
