#include "ros/ros.h"
#include "t2_package/robot_id.h"

void callback(const t2_package::robot_id::ConstPtr& msg)
{
	ROS_INFO("Received Message from Robot %u model %s", msg->id, msg->model.c_str());
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "t2_subscriber_node");
	ros::NodeHandle nh;
	ros::Subscriber sub = nh.subscribe("t2_topic", 1000, callback);
	ros::spin();
	return 0;
}
