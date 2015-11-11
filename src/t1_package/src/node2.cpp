#include <ros/ros.h>
int main( int argc, char** argv )
{
	ros::init( argc, argv, "trsa_node2" );
	ros::NodeHandle node;
	ros::Rate rate(10);
	while ( ros::ok() )
	{
		ROS_INFO( "Yet another node" );
		rate.sleep();
 	}
	return 0;
}
