#include "trabfinal/uav_segmentation.h"

UAV_Segmentation::UAV_Segmentation(ros::NodeHandle n) :
n_(n)
{
  cloud_sub_ = n_.subscribe("/autoland/octomap_cloud", 1000, &UAV_Segmentation::cloudCallback, this);
  uav_control = n_.advertise<trabfinal::gpsXY>("/autoland/laserPosUAV", 10);
  treated_cloud_pub_ = n_.advertise<sensor_msgs::PointCloud2>("/autoland/uav_cloud",1);
}

void UAV_Segmentation::cloudCallback (const sensor_msgs::PointCloud2::ConstPtr& cloud_in)
{
  ROS_INFO("Processing!");
  /************************ CENTER AND LEFT BOXES ***************************************/
  //Creating point cloud and convert ROS Message
  pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_cloud (new pcl::PointCloud<pcl::PointXYZ> ());
  pcl::PointCloud<pcl::PointXYZ>::Ptr seg_cloud (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::fromROSMsg(*cloud_in, *pcl_cloud);
  //Create and define filter parameters

  pcl::PassThrough<pcl::PointXYZ> pass3;
  pass3.setFilterFieldName("x");
  pass3.setFilterLimits(-2, 2); //-0.5 0.5
  pass3.setInputCloud(pcl_cloud);
  pass3.filter(*pcl_cloud);

  pcl::PassThrough<pcl::PointXYZ> pass;
  pass.setFilterFieldName("y");
  pass.setFilterLimits(-2, 2); //-0.5 0.5
  pass.setInputCloud(pcl_cloud);
  pass.filter(*pcl_cloud);

  pcl::PassThrough<pcl::PointXYZ> pass2;
  pass2.setFilterFieldName("z");
  pass2.setFilterLimits(0, 3.0); //-0.5 0.5
  pass2.setInputCloud(pcl_cloud);
  pass2.filter(*pcl_cloud);

  //Model fitting process ->RANSAC
  pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
  pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
  pcl::SACSegmentation<pcl::PointXYZ> seg;
  seg.setOptimizeCoefficients (true);
  seg.setModelType (pcl::SACMODEL_PARALLEL_PLANE);
  seg.setMethodType (pcl::SAC_RANSAC);
  seg.setDistanceThreshold (0.03); //0.03
  seg.setAxis (Eigen::Vector3f(1, 0, 0));
  seg.setEpsAngle (0.1); //0.02
  seg.setInputCloud (pcl_cloud);
  seg.segment (*inliers, *coefficients);
  //Verify if inliers is not empty
  if (inliers->indices.size () == 0)
    return;
  pcl::PointCloud<pcl::PointXYZ>::Ptr treated_cloud (new pcl::PointCloud<pcl::PointXYZ> ());
  for (std::vector<int>::const_iterator it = inliers->indices.begin(); it != inliers->indices.end (); ++it)
    treated_cloud->push_back(pcl_cloud->points[*it]);

  pcl::ExtractIndices<pcl::PointXYZ> extract;
	extract.setInputCloud(pcl_cloud);
	extract.setIndices(inliers);
	extract.setNegative(true);
	extract.filter(*seg_cloud);

  //Create and define radial filter parameters
  //pcl::RadiusOutlierRemoval<pcl::PointXYZ> radialFilter;
  //radialFilter.setInputCloud(treated_cloud);
  //radialFilter.setRadiusSearch(0.03);
  //radialFilter.setMinNeighborsInRadius (20);
  //radialFilter.filter (*treated_cloud);

  //Apply clustering algorithm
  pcl::search::KdTree<pcl::PointXYZ>::Ptr kdtree (new pcl::search::KdTree<pcl::PointXYZ>);
  kdtree->setInputCloud (seg_cloud);
  std::vector<pcl::PointIndices> cluster_indices;
  pcl::EuclideanClusterExtraction<pcl::PointXYZ> ec;
  ec.setClusterTolerance (0.5);
  ec.setMinClusterSize (2);
  ec.setMaxClusterSize (150);
  ec.setSearchMethod (kdtree);
  ec.setInputCloud (seg_cloud);
  ec.extract (cluster_indices);
  pcl::PointCloud<pcl::PointXYZI>::Ptr cluster_cloud (new pcl::PointCloud<pcl::PointXYZI> ());
  pcl::PointXYZI cluster_point;
  double cluster_final_average;
  int cluster_id=0;
  float x1 = 0.0, y1 = 0.0, z1 = 0.0;
  float x2 = 0.0, y2 = 0.0, z2 = 0.0;
  float x3 = 0.0, y3 = 0.0, z3 = 0.0;
  int total1 = 0, total2 = 0, total3 = 0;
  bool hasUAV1, hasCup2, hasCup3;

  for (std::vector<pcl::PointIndices>::const_iterator it = cluster_indices.begin (); it != cluster_indices.end ();
  ++it, cluster_id+=1)
  {
    for (std::vector<int>::const_iterator pit = it->indices.begin (); pit != it->indices.end (); pit++)
    {
      cluster_point.x = seg_cloud->points[*pit].x;
      cluster_point.y = seg_cloud->points[*pit].y;
      cluster_point.z = seg_cloud->points[*pit].z;
      cluster_point.intensity = cluster_id;
      cluster_cloud->push_back(cluster_point);

      if(cluster_id == 0){
        x1 += seg_cloud->points[*pit].x;
        y1 += seg_cloud->points[*pit].y;
        z1 += seg_cloud->points[*pit].z;
        total1++;
      }
    }
  }
  if(total1 != 0 ){
    x1 = x1/total1;
    y1 = y1/total1;
    z1 = z1/total1;
    hasUAV1=true;
  }else{
    hasUAV1 = false;
  }


  //Publish message
  sensor_msgs::PointCloud2 cloud;
  pcl::toROSMsg(*cluster_cloud, cloud);
  cloud.header.stamp = ros::Time::now();
  cloud.header.frame_id = cloud_in->header.frame_id;
  treated_cloud_pub_.publish(cloud);


  //Geometry
  geometry_msgs::PointStamped cupPoint1;


  tf::Quaternion q;

  geometry_msgs::PointStamped cupSensorPoint1;


  static tf::TransformBroadcaster tfBc1;

  tf::Transform tfCup1;

  cupPoint1.header.frame_id = "base_footprint";


  cupPoint1.header.stamp = cloud_in->header.stamp;


  cupPoint1.point.x = x1;


  cupPoint1.point.y = y1;


  cupPoint1.point.z = z1;


  ROS_INFO("Cup 1: X=%f Y=%f Z=%f", cupPoint1.point.x, cupPoint1.point.y, cupPoint1.point.z);
  trabfinal::gpsXY uavPos;
  uavPos.x=cupPoint1.point.x;
  uavPos.y=cupPoint1.point.y;
  uavPos.z=cupPoint1.point.z;

  uav_control.publish(uavPos);


  tf_listener.transformPoint("base_footprint", cupPoint1, cupSensorPoint1);


  tfCup1.setOrigin( tf::Vector3(cupSensorPoint1.point.x, cupSensorPoint1.point.y, cupSensorPoint1.point.z) );

  ROS_INFO("Sensor Frame Cup 1: X=%f Y=%f Z=%f", cupSensorPoint1.point.x, cupSensorPoint1.point.y, cupSensorPoint1.point.z);

  q.setRPY(0, 0, 0);

  tfCup1.setRotation(q);


  tfBc1.sendTransform(tf::StampedTransform(tfCup1, cloud_in->header.stamp, "base_footprint", "uav1"));

  ROS_INFO("All Sent!");

}
