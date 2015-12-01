#include "t8_package/laser_2_cloud.h"


LaserScan_2_PointCloud::LaserScan_2_PointCloud(ros::NodeHandle n) : n_(n)
{
  scan_sub_ = n_.subscribe("/scan", 1000, &LaserScan_2_PointCloud::scanCallback, this);
  cloud_pub_ = n_.advertise<sensor_msgs::PointCloud2>("/laser_cloud",1);
  transform = Eigen::Matrix4f::Identity();
}

void LaserScan_2_PointCloud::scanCallback (const sensor_msgs::LaserScan::ConstPtr& scan_in)
{
   tf::StampedTransform transform2;

  sensor_msgs::PointCloud2 cloud;
  //ROS_INFO("Olá Mundo!");

  if(!listener_.waitForTransform(
        scan_in->header.frame_id,
        "/base_link",
        scan_in->header.stamp + ros::Duration().fromSec(scan_in->ranges.size()*scan_in->time_increment),
        ros::Duration(1.0))){
     ROS_INFO("Waiting for transform!");
     return;
  }
  try{
    projector_.transformLaserScanToPointCloud(scan_in->header.frame_id,*scan_in, cloud,listener_);
    cloud_pub_.publish(cloud);
  } catch(tf::ExtrapolationException ex){
    ROS_INFO("%s", ex.what());
  }


}
