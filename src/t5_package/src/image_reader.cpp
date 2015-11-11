#include <opencv2/opencv.hpp>
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <image_transport/image_transport.h>


void imageClbk ( const sensor_msgs::ImageConstPtr& msg)
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
  cv::imshow( "Image RAW", cvImagePtr->image ); // opens a named window to display the image
  cv::waitKey(1);
}

void processedClbk ( const sensor_msgs::ImageConstPtr& msg)
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
  cv::imshow( "Image Processed", cvImagePtr->image ); // opens a named window to display the image
  cv::waitKey(1);
}

int main(int argc, char **argv)
{
  ros::init( argc, argv, "image_reader" );

  ros::NodeHandle nh;
  image_transport::ImageTransport it(nh);
  image_transport::Subscriber imageSub = it.subscribe("/camera/image_raw", 1, imageClbk);
  image_transport::Subscriber processedSub = it.subscribe("/camera/image_processed", 1, processedClbk);
  ros::spin();

}
