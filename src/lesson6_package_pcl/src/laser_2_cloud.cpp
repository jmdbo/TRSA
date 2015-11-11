#include "lesson6_package_pcl/laser_2_cloud.h"


LaserScan_2_PointCloud::LaserScan_2_PointCloud(ros::NodeHandle n) : n_(n)
{
  scan_sub_ = n_.subscribe("/laser_scan", 1000, &LaserScan_2_PointCloud::scanCallback, this);
  cloud_pub_ = n_.advertise<sensor_msgs::PointCloud2>("/laser_cloud",1);
  servo_sub = n_.subscribe("/servo_tilt_angle", 1000, &LaserScan_2_PointCloud::servoCallback, this);
  transform = Eigen::Matrix4f::Identity();
}

void LaserScan_2_PointCloud::servoCallback(const std_msgs::Float64::ConstPtr& tilt_angle)
{
  transform (0,0) = cos(-M_PI + tilt_angle->data);
  transform (0,2) = sin(-M_PI + tilt_angle->data);
  transform (2,0) = -sin(-M_PI + tilt_angle->data);
  transform (2,2) = cos (-M_PI + tilt_angle->data);
}

void LaserScan_2_PointCloud::scanCallback (const sensor_msgs::LaserScan::ConstPtr& scan_in)
{
  sensor_msgs::PointCloud2 cloud;
  projector_.projectLaser(*scan_in, cloud);

  pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_cloud (new pcl::PointCloud<pcl::PointXYZ> ());
  pcl::fromROSMsg(cloud, *pcl_cloud);
  pcl::transformPointCloud(*pcl_cloud, *pcl_cloud, transform);
  pcl::toROSMsg(*pcl_cloud, cloud);

  cloud.header.stamp = ros::Time::now();
  cloud.header.frame_id = scan_in->header.frame_id;
  cloud_pub_.publish(cloud);
}
