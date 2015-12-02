#include "t8_package/cup_segmentation.h"

Cup_Segmentation::Cup_Segmentation(ros::NodeHandle n) :
n_(n)
{
  cloud_sub_ = n_.subscribe("/octomap_cloud", 1000, &Cup_Segmentation::cloudCallback, this);
  treated_cloud_pub_ = n_.advertise<sensor_msgs::PointCloud2>("/cup_cloud",1);
}

void Cup_Segmentation::cloudCallback (const sensor_msgs::PointCloud2::ConstPtr& cloud_in)
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
  pass3.setFilterLimits(0, 1.2); //-0.5 0.5
  pass3.setInputCloud(pcl_cloud);
  pass3.filter(*pcl_cloud);

  pcl::PassThrough<pcl::PointXYZ> pass;
  pass.setFilterFieldName("y");
  pass.setFilterLimits(-0.7, 0.1); //-0.5 0.5
  pass.setInputCloud(pcl_cloud);
  pass.filter(*pcl_cloud);

  pcl::PassThrough<pcl::PointXYZ> pass2;
  pass2.setFilterFieldName("z");
  pass2.setFilterLimits(0.0, 1.0); //-0.5 0.5
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
  ec.setClusterTolerance (0.06);
  ec.setMinClusterSize (6);
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
  bool hasCup1, hasCup2, hasCup3;

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
      } else if (cluster_id == 1){
        x2 += seg_cloud->points[*pit].x;
        y2 += seg_cloud->points[*pit].y;
        z2 += seg_cloud->points[*pit].z;
        total2++;
      } else if (cluster_id == 2){
        x3 += seg_cloud->points[*pit].x;
        y3 += seg_cloud->points[*pit].y;
        z3 += seg_cloud->points[*pit].z;
        total3++;
      }
    }
  }
  if(total1 != 0 ){
    x1 = x1/total1;
    y1 = y1/total1;
    z1 = z1/total1;
    hasCup1=true;
  }else{
    hasCup1 = false;
  }
  if(total2 != 0 ){
    x2 = x2/total2;
    y2 = y2/total2;
    z2 = z2/total2;

    hasCup2 = true;
  } else {
    hasCup2 = false;
  }

  if(total3 != 0){
    x3 = x3/total2;
    y3 = y3/total2;
    z3 = z3/total2;
    hasCup3 = true;
  } else{
    hasCup3 = false;
  }


  //Publish message
  sensor_msgs::PointCloud2 cloud;
  pcl::toROSMsg(*cluster_cloud, cloud);
  cloud.header.stamp = ros::Time::now();
  cloud.header.frame_id = cloud_in->header.frame_id;
  treated_cloud_pub_.publish(cloud);


  //Geometry
  geometry_msgs::PointStamped cupPoint1;
  geometry_msgs::PointStamped cupPoint2;
  geometry_msgs::PointStamped cupPoint3;

  tf::Quaternion q;

  geometry_msgs::PointStamped cupSensorPoint1;
  geometry_msgs::PointStamped cupSensorPoint2;
  geometry_msgs::PointStamped cupSensorPoint3;

  static tf::TransformBroadcaster tfBc1;
  static tf::TransformBroadcaster tfBc2;
  static tf::TransformBroadcaster tfBc3;

  tf::Transform tfCup1;
  tf::Transform tfCup2;
  tf::Transform tfCup3;

  cupPoint1.header.frame_id = "base_footprint";
  cupPoint2.header.frame_id = "base_footprint";
  cupPoint3.header.frame_id = "base_footprint";

  cupPoint1.header.stamp = cloud_in->header.stamp;
  cupPoint2.header.stamp = cloud_in->header.stamp;
  cupPoint3.header.stamp = cloud_in->header.stamp;

  cupPoint1.point.x = x1;
  cupPoint2.point.x = x2;
  cupPoint3.point.x = x3;

  cupPoint1.point.y = y1;
  cupPoint2.point.y = y2;
  cupPoint3.point.y = y3;

  cupPoint1.point.z = z1;
  cupPoint2.point.z = z2;
  cupPoint3.point.z = z3;

  ROS_INFO("Cup 1: X=%f Y=%f Z=%f", cupPoint1.point.x, cupPoint1.point.y, cupPoint1.point.z);
  ROS_INFO("Cup 2: X=%f Y=%f Z=%f", cupPoint2.point.x, cupPoint2.point.y, cupPoint2.point.z);
  ROS_INFO("Cup 3: X=%f Y=%f Z=%f", cupPoint3.point.x, cupPoint3.point.y, cupPoint3.point.z);


  tf_listener.transformPoint("sensors_frame", cupPoint1, cupSensorPoint1);
  tf_listener.transformPoint("sensors_frame", cupPoint2, cupSensorPoint2);
  tf_listener.transformPoint("sensors_frame", cupPoint3, cupSensorPoint3);


  tfCup1.setOrigin( tf::Vector3(cupSensorPoint1.point.x, cupSensorPoint1.point.y, cupSensorPoint1.point.z) );
  tfCup2.setOrigin( tf::Vector3(cupSensorPoint2.point.x, cupSensorPoint2.point.y, cupSensorPoint2.point.z) );
  tfCup3.setOrigin( tf::Vector3(cupSensorPoint3.point.x, cupSensorPoint3.point.y, cupSensorPoint3.point.z) );

  ROS_INFO("Sensor Frame Cup 1: X=%f Y=%f Z=%f", cupSensorPoint1.point.x, cupSensorPoint1.point.y, cupSensorPoint1.point.z);
  ROS_INFO("Sensor Frame Cup 2: X=%f Y=%f Z=%f", cupSensorPoint2.point.x, cupSensorPoint2.point.y, cupSensorPoint2.point.z);
  ROS_INFO("Sensor Frame Cup 3: X=%f Y=%f Z=%f", cupSensorPoint3.point.x, cupSensorPoint3.point.y, cupSensorPoint3.point.z);

  q.setRPY(0, 0, 0);

  tfCup1.setRotation(q);
  tfCup2.setRotation(q);
  tfCup3.setRotation(q);

  tfBc1.sendTransform(tf::StampedTransform(tfCup1, cloud_in->header.stamp, "sensors_frame", "cup1"));
  tfBc2.sendTransform(tf::StampedTransform(tfCup2, cloud_in->header.stamp, "sensors_frame", "cup2"));
  tfBc3.sendTransform(tf::StampedTransform(tfCup3, cloud_in->header.stamp, "sensors_frame", "cup3"));
  ROS_INFO("All Sent!");

}
