#include <ros/ros.h>
#include <ros/package.h>

#include <sensor_msgs/Image.h>
#include <sensor_msgs/fill_image.h>
#include <image_transport/image_transport.h>

#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

#include <image_geometry/pinhole_camera_model.h>
#include <camera_info_manager/camera_info_manager.h>



int main(int argc, char **argv)
{
    ros::init( argc, argv, "camera_stream" );

    ros::NodeHandle node("~");
    ros::Rate rate( 30.0 );

    sensor_msgs::Image rosImgRaw, rosImgRect;
    std::string camera_name, video_name;

    // get params from ROS ParameterServer or set default values
    node.param<std::string>( "camera_name" , camera_name, "trsa_camera" );
    node.param<std::string>( "video_name" , video_name  , "test.mov"    );

    if ( !node.hasParam("camera_name") )
        ROS_WARN("Undefined parameter 'camera_name'\tSetting default: trsa_camera");
    if ( !node.hasParam("camera_name") )
        ROS_WARN("Undefined parameter 'video_name'\tSetting default: test.mov");

    // create and open video handler (for video files and webcams)
    std::stringstream ss;
    ss << ros::package::getPath( "t5_package" ) << "/video/" << video_name;

    cv::VideoCapture cap;
    cap.open( ss.str() );

    if ( !cap.isOpened() )
    {
        ROS_FATAL( "Unable to open video stream device: %s", ss.str().c_str() );
        ROS_BREAK();
    }


    // create and initialise ROS and OpenCV variables
    camera_info_manager::CameraInfoManager* cInfoMgr;
    sensor_msgs::CameraInfo camInfo;
    image_geometry::PinholeCameraModel camModel;

    cv::Mat frame, rectified;

    std::string frame_id = "/base_link";
    rosImgRaw.header.frame_id = frame_id;
    rosImgRect.header.frame_id = frame_id;

    image_transport::ImageTransport it( node );
    image_transport::Publisher pubRaw  = it.advertise("/camera/image_raw", 1);
    image_transport::Publisher pubRect = it.advertise("/camera/image_rect",1);

    ros::Publisher pubCInfo = node.advertise<sensor_msgs::CameraInfo>( "/camera/camera_info", 1 );


    // check the existence of the calibration matrix
    bool hasCalibMat = false;

    try
    {
        std::stringstream ss;
        ss << "package://t5_package/calibration/" << camera_name << ".yaml";

        cInfoMgr = new camera_info_manager::CameraInfoManager( ros::NodeHandle(node, "/camera"),
                                                               camera_name, ss.str() );

        if ( cInfoMgr->isCalibrated() )
        {
            ROS_INFO( " === Calibration matrix was found and loaded === " );
            ROS_INFO( " Streaming recorded video ... " );
        }
        else
            ROS_INFO( " Streaming calibration frames ... " );
    }
    catch( cv::Exception exc )
    {
            std::cout << "Error in CameraInfo: " <<  exc.msg << std::endl;
    }


    // main loop

    unsigned int img_idx = 0;

    while ( ros::ok() )
    {

        // There is no calibration matrix yet,
        // let's publish only the calibration images
        // in order to calibrate the camera
        if ( !cInfoMgr->isCalibrated() )
        {
            std::stringstream ss1;
            ss1 << ros::package::getPath( "t5_package" ) << "/calibration/images/" << img_idx++ << ".jpeg";

            frame = cv::imread( ss1.str(), CV_LOAD_IMAGE_COLOR );

            if ( img_idx > 126 )
            {
                ROS_WARN(" Calibrate Now !!! ");

                ros::spinOnce();

                img_idx--;
            }
        }

        // The calibration matrix was found, therefore let's
        // stream the video recorded from the respective camera
        // and compare the frames (raw versus rectified )
        else
        {
            cap >> frame;

            if ( !frame.data )
            {
                ros::shutdown();
                continue;
            }

            // create calibration model from camera info data
            camInfo = cInfoMgr->getCameraInfo();
            camInfo.header.frame_id = frame_id;
            camModel.fromCameraInfo( camInfo );

            camModel.rectifyImage( frame, rectified );

            sensor_msgs::fillImage( rosImgRect, "bgr8", rectified.rows,
                               rectified.cols, rectified.step, rectified.data );

            camInfo.header.stamp = ros::Time::now();

            pubCInfo.publish( camInfo );
            pubRect.publish( rosImgRect );
        }

        sensor_msgs::fillImage( rosImgRaw, "bgr8", frame.rows, frame.cols,
                                frame.step, frame.data );

        pubRaw.publish( rosImgRaw );

        rate.sleep();
    }
}
