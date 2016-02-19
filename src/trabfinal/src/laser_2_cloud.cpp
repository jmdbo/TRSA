#include "ros/ros.h"
#include "trabfinal/laser_2_cloud.h"


LaserScan_2_PointCloud::LaserScan_2_PointCloud(ros::NodeHandle n): n_(n)
{
	scan_sub_ = n_.subscribe("/kelp/uav/laser_scan", 1000, &LaserScan_2_PointCloud::scanCallback, this);
	cloud_pub_ = n_.advertise<sensor_msgs::PointCloud2>("/autoland/laser_cloud",1);
	servo_sub_ = n_.subscribe("/kelp/uav/laser_scan/joint_state", 1000, &LaserScan_2_PointCloud::servoCallback, this);
	transform = Eigen::Matrix4f::Identity();
}

void LaserScan_2_PointCloud::run()
{
	ros::spin();
}


void LaserScan_2_PointCloud::scanCallback (const sensor_msgs::LaserScan::ConstPtr& scan_in)
{
	sensor_msgs::PointCloud2 cloud;
	projector_.transformLaserScanToPointCloud("hokuyo_frame", *scan_in, cloud, tfListener_);
	/*
	projector_.projectLaser(*scan_in, cloud);

	pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_cloud (new pcl::PointCloud<pcl::PointXYZ> ());
	pcl::fromROSMsg(cloud, *pcl_cloud);
	pcl::transformPointCloud(*pcl_cloud, *pcl_cloud, transform);
	pcl::toROSMsg(*pcl_cloud, cloud);

	cloud.header.stamp = ros::Time::now();
	cloud.header.frame_id = scan_in->header.frame_id;*/
	cloud_pub_.publish(cloud);
}

void LaserScan_2_PointCloud::servoCallback(const sensor_msgs::JointState& tilt_angle){
	transform (0,0) = cos (-(M_PI/2) + tilt_angle.position[1]);
	transform (0,2) = sin(-(M_PI/2) + tilt_angle.position[1]);
	transform (2,0) = -sin (-(M_PI/2) + tilt_angle.position[1]);
	transform (2,2) = cos (-(M_PI/2) + tilt_angle.position[1]);
}
