cmake_minimum_required(VERSION 2.8.3)
project( kelp_ros )

## Find catkin macros and libraries
find_package( catkin REQUIRED COMPONENTS roscpp
                                         roslib
                                         sensor_msgs
                                         std_msgs
                                         geometry_msgs
                                         message_generation
                                         image_transport
)


find_package( OpenSceneGraph REQUIRED COMPONENTS osgDB osgUtil osgViewer osgGA )
find_package( Bullet REQUIRED )
find_package( GeographicLib REQUIRED )


###################################
## catkin specific configuration ##
###################################

catkin_package (
  INCLUDE_DIRS
  LIBRARIES kelp
  CATKIN_DEPENDS roscpp roslib sensor_msgs std_msgs geometry_msgs image_transport
  DEPENDS OpenSceneGraph Bullet GeographicLib
)
