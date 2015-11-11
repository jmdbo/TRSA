
#include <ros/ros.h>
#include "t4_package/Thermometer.h"


int main( int argc, char** argv )
{
    ros::init( argc, argv, "thermometer" );

    Thermometer sensor;

    sensor.run();

    return EXIT_SUCCESS;
}
