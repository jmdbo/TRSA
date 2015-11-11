#include <ros/ros.h>
#include <ros/package.h>

#include <opencv2/opencv.hpp>
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <image_transport/image_transport.h>



int main(int argc, char **argv)
{
  ros::init( argc, argv, "camera_driver" );

  cv::VideoCapture cap(0); // open the camera with <device_index>
  if ( !cap.isOpened() ) // check if we succeeded
    return -1;


  sensor_msgs::Image ros_image;
  cv_bridge::CvImage out_msg;
  ros::NodeHandle nh;
  image_transport::ImageTransport it(nh);
  image_transport::Publisher imagePub = it.advertise("/camera/image_raw", 1);
  cv::Mat frame; // create just an empty image without any
  // information regarding its type and dimensions
  while(ros::ok())
  {
    cap >> frame; // get a new frame from camera
    if ( !frame.data ) // check if a new frame was successfully retrieve
    break; // this can fail if the camera is not available anymore
    // or, in the case of a video file, we have reached the end of file.
    out_msg.header.stamp = ros::Time::now() ; // timestamp from the system clock
    out_msg.header.frame_id = "/camera_link"; // camera position in the world
    out_msg.encoding = sensor_msgs::image_encodings::BGR8; // or other types
    out_msg.image = frame; // your cv::Mat
    out_msg.toImageMsg( ros_image );
    // now we can publish the image…
    imagePub.publish(ros_image); // image_transport::Publisher
  }

}
