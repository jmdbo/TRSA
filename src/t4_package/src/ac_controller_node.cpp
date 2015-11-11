#include <ros/ros.h>
#include "t4_package/ACController.h"


int main( int argc, char** argv )
{
    ros::init( argc, argv, "ac_controller" );

    ACController controller;

    controller.run();

    return EXIT_SUCCESS;
}
