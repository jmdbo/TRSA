#include "ros/ros.h"
#include "t2_package/Set_Robot_Model.h"


int main(int argc, char **argv)
{
  ros::init(argc, argv, "t2_client_node");
  if (argc != 2)
  {
    ROS_INFO("usage: Set_Robot_Model model");
    return 1;
  }
  ros::NodeHandle nh;

  ros::ServiceClient client = nh.serviceClient<t2_package::Set_Robot_Model>("Set_Robot_Model");
  
  t2_package::Set_Robot_Model srv;
  srv.request.model = argv[1];
  if (client.call(srv))
  {
    ROS_INFO("New Robot ID Model: %u : %s", srv.response.robotID.id, srv.response.robotID.model.c_str());
  }
  else
  {
    ROS_ERROR("Failed to call service Set_Robot_Model");
    return 1;
  }

  return 0;
}
