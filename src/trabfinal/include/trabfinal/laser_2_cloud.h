#ifndef _laser_2_cloud_H_
#define _laser_2_cloud_H_

#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "sensor_msgs/PointCloud.h"
#include "laser_geometry/laser_geometry.h"
#include "std_msgs/Float64.h"
#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/transforms.h>


class  LaserScan_2_PointCloud //class
{
    public:

        LaserScan_2_PointCloud(ros::NodeHandle n); //construtor
        ~ LaserScan_2_PointCloud(){};
        void run();

    private:

      ros::NodeHandle n_;
      laser_geometry::LaserProjection projector_;
      ros::Subscriber scan_sub_, servo_sub_;
      ros::Publisher cloud_pub_;
      Eigen::Matrix4f transform;
      void scanCallback (const sensor_msgs::LaserScan::ConstPtr& scan_in);
      void servoCallback(const std_msgs::Float64::ConstPtr& tilt_angle);
};

#endif
