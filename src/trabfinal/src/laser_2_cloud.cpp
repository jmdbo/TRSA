#include "ros/ros.h"
#include "trabfinal/laser_2_cloud.h"


LaserScan_2_PointCloud::LaserScan_2_PointCloud(ros::NodeHandle n): n_(n)
{
	scan_sub_ = n_.subscribe("/kelp/uav/laser_scan", 1000, &LaserScan_2_PointCloud::scanCallback, this);
	cloud_pub_ = n_.advertise<sensor_msgs::PointCloud2>("/autoland/laser_cloud",1);
}

void LaserScan_2_PointCloud::run()
{
	ros::spin();
}


void LaserScan_2_PointCloud::scanCallback (const sensor_msgs::LaserScan::ConstPtr& scan_in)
{
	sensor_msgs::PointCloud2 cloud;
	//Convert LaserScan to PointCloud using the tf from the laser
	projector_.transformLaserScanToPointCloud("hokuyo_frame", *scan_in, cloud, tfListener_);
	cloud_pub_.publish(cloud);
}
