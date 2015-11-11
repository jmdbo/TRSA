#include "lesson6_package_pcl/box_segmentation.h"

Box_Segmentation::Box_Segmentation(ros::NodeHandle n) :
n_(n)
{
  cloud_sub_ = n_.subscribe("/octomap_cloud", 1000, &Box_Segmentation::cloudCallback, this);
  treated_cloud_pub_ = n_.advertise<sensor_msgs::PointCloud2>("/box_cloud",1);
}

void Box_Segmentation::cloudCallback (const sensor_msgs::PointCloud2::ConstPtr& cloud_in)
{
  /************************ CENTER AND LEFT BOXES ***************************************/
  //Creating point cloud and convert ROS Message
  pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_cloud (new pcl::PointCloud<pcl::PointXYZ> ());
  pcl::fromROSMsg(*cloud_in, *pcl_cloud);
  //Create and define filter parameters
  pcl::PassThrough<pcl::PointXYZ> pass;
  pass.setFilterFieldName("y");
  pass.setFilterLimits(-0.5, 0.5); //-0.5 0.5
  pass.setInputCloud(pcl_cloud);
  pass.filter(*pcl_cloud);

  //Model fitting process ->RANSAC
  pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
  pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
  pcl::SACSegmentation<pcl::PointXYZ> seg;
  seg.setOptimizeCoefficients (true);
  seg.setModelType (pcl::SACMODEL_PERPENDICULAR_PLANE);
  seg.setMethodType (pcl::SAC_RANSAC);
  seg.setDistanceThreshold (0.03); //0.03
  seg.setAxis (Eigen::Vector3f(1, 0, 0));
  seg.setEpsAngle (0.02); //0.02
  seg.setInputCloud (pcl_cloud);
  seg.segment (*inliers, *coefficients);
  //Verify if inliers is not empty
  if (inliers->indices.size () == 0)
    return;
  pcl::PointCloud<pcl::PointXYZ>::Ptr treated_cloud (new pcl::PointCloud<pcl::PointXYZ> ());
  for (std::vector<int>::const_iterator it = inliers->indices.begin(); it != inliers->indices.end (); ++it)
    treated_cloud->push_back(pcl_cloud->points[*it]);

  //Create and define radial filter parameters
  pcl::RadiusOutlierRemoval<pcl::PointXYZ> radialFilter;
  radialFilter.setInputCloud(treated_cloud);
  radialFilter.setRadiusSearch(0.03);
  radialFilter.setMinNeighborsInRadius (20);
  radialFilter.filter (*treated_cloud);

  //Apply clustering algorithm
  pcl::search::KdTree<pcl::PointXYZ>::Ptr kdtree (new pcl::search::KdTree<pcl::PointXYZ>);
  kdtree->setInputCloud (treated_cloud);
  std::vector<pcl::PointIndices> cluster_indices;
  pcl::EuclideanClusterExtraction<pcl::PointXYZ> ec;
  ec.setClusterTolerance (0.03);
  ec.setMinClusterSize (100);
  ec.setMaxClusterSize (10000);
  ec.setSearchMethod (kdtree);
  ec.setInputCloud (treated_cloud);
  ec.extract (cluster_indices);
  pcl::PointCloud<pcl::PointXYZI>::Ptr cluster_cloud (new pcl::PointCloud<pcl::PointXYZI> ());
  pcl::PointXYZI cluster_point;
  double cluster_final_average;
  int cluster_id=0;
  for (std::vector<pcl::PointIndices>::const_iterator it = cluster_indices.begin (); it != cluster_indices.end ();
  ++it, cluster_id+=50000)
  {
    for (std::vector<int>::const_iterator pit = it->indices.begin (); pit != it->indices.end (); pit++)
    {
      cluster_point.x = treated_cloud->points[*pit].x;
      cluster_point.y = treated_cloud->points[*pit].y;
      cluster_point.z = treated_cloud->points[*pit].z;
      cluster_point.intensity = cluster_id;
      cluster_cloud->push_back(cluster_point);
    }
  }

  /************************ RIGHT BOX ***************************************/
  pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_right_cloud (new pcl::PointCloud<pcl::PointXYZ> ());
  pcl::fromROSMsg(*cloud_in, *pcl_right_cloud);

  pass.setFilterLimits(-0.9, -0.5); //-0.5 0.5
  pass.setInputCloud(pcl_right_cloud);
  pass.filter(*pcl_right_cloud);


  //Model fitting process ->RANSAC
  pcl::ModelCoefficients::Ptr coefficientsRight (new pcl::ModelCoefficients);
  pcl::PointIndices::Ptr inliersRight (new pcl::PointIndices);
  //Segmentation
  seg.setInputCloud (pcl_right_cloud);
  seg.segment (*inliersRight, *coefficientsRight);
  //Verify if inliers is not empty
  if (inliersRight->indices.size () == 0)
    return;

  pcl::PointCloud<pcl::PointXYZ>::Ptr treated_right_cloud (new pcl::PointCloud<pcl::PointXYZ> ());
  for (std::vector<int>::const_iterator it = inliersRight->indices.begin(); it != inliersRight->indices.end (); ++it)
    treated_right_cloud->push_back(pcl_right_cloud->points[*it]);

  //Redefine radial filter parameters
  radialFilter.setInputCloud(treated_right_cloud);
  radialFilter.filter (*treated_right_cloud);

  //Apply clustering algorithm
  kdtree->setInputCloud (treated_right_cloud);
  std::vector<pcl::PointIndices> cluster_right_indices;
  ec.setSearchMethod(kdtree);
  ec.setInputCloud (treated_right_cloud);
  ec.extract (cluster_right_indices);
  //Set id for right cluster
  int right_cluster_id = 31559-34204+40581;
  for (std::vector<pcl::PointIndices>::const_iterator it = cluster_right_indices.begin (); it != cluster_right_indices.end ();
  ++it, ++cluster_id)
  {
    for (std::vector<int>::const_iterator pit = it->indices.begin (); pit != it->indices.end (); pit++)
    {
      cluster_point.x = treated_right_cloud->points[*pit].x;
      cluster_point.y = treated_right_cloud->points[*pit].y;
      cluster_point.z = treated_right_cloud->points[*pit].z;
      cluster_point.intensity = right_cluster_id;
      cluster_cloud->push_back(cluster_point);
    }
  }
  //Publish message
  sensor_msgs::PointCloud2 cloud;
  pcl::toROSMsg(*cluster_cloud, cloud);
  cloud.header.stamp = ros::Time::now();
  cloud.header.frame_id = cloud_in->header.frame_id;
  treated_cloud_pub_.publish(cloud);

}
