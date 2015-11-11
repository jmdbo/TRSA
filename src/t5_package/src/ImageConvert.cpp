#include <ros/ros.h>
#include "t5_package/ImageConvert.h"

ImageConvert::ImageConvert()
{
  image_transport::ImageTransport it(node);
  m_imageSub = it.subscribe("/camera/image_raw", 1, &ImageConvert::imageClbk, this);
  m_imagePub = it.advertise("/camera/image_processed", 1);
  m_size = cv::Size(21,21);
  ROS_INFO("INITIALIZED!");

}

void ImageConvert::run()
{
  ros::spin();
}

void ImageConvert::imageClbk ( const sensor_msgs::ImageConstPtr& msg)
{
  cv_bridge::CvImagePtr cvImagePtr;

  try
  {
    // toCvCopy method copies the image data and returns a mutable CvImage
    cvImagePtr = cv_bridge::toCvCopy( msg );
    // toCvShare method shares the image data, returning a const CvImage
    // cv_bridge::CvImageConstPtr cvImagePtr = cv_bridge::toCvShare( rosImage );
  } catch (cv_bridge::Exception &e) {
    ROS_ERROR( "cv_bridge exception: %s", e.what() );
  }

  //let's process the image using the pointer!
  cv::cvtColor(cvImagePtr->image, cvImagePtr->image, CV_BGR2GRAY);
  cv::cvtColor(cvImagePtr->image, cvImagePtr->image, CV_GRAY2BGR);
  //cvImagePtr->encoding="mono8";
  cv::GaussianBlur(cvImagePtr->image, cvImagePtr->image, m_size, 0, 0);
  // now we can publish the image…
  m_imagePub.publish(cvImagePtr->toImageMsg()); // image_transport::Publisher

}
