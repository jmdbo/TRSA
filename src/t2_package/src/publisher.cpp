#include "ros/ros.h"
#include "t2_package/robot_id.h"
#include "t2_package/Set_Robot_Model.h"

unsigned int id = 106;
std::string model = "TRSABot";

bool service_callback(t2_package::Set_Robot_Model::Request &req,t2_package::Set_Robot_Model::Response &res)
{
	model = req.model;
	ROS_INFO("Set_Robot_Model call: %s>> %s", model.c_str(), req.model.c_str());
	res.robotID.id = id;
	res.robotID.model = model;
	return true;
}

int main(int argc, char **argv)
{
	ros::init( argc, argv, "t2_publisher_node");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<t2_package::robot_id>("t2_robot_id_topic", 1000);
	ros::ServiceServer service = nh.advertiseService("Set_Robot_Model", service_callback);
	ros::Rate loop_rate(10);
	t2_package::robot_id msg;
	while (ros::ok())
	{
		msg.header.stamp = ros::Time::now();
		msg.header.frame_id = "/base_link";
		msg.id = id;
		msg.model = model;
		ROS_INFO("Published robot_id message : %d %s", msg.id, msg.model.c_str());
		pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}
