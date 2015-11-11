cmake_minimum_required(VERSION 2.8.3)
project( t5_package )

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  image_geometry
  camera_info_manager
  roslib
)


###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES t5_package
#  CATKIN_DEPENDS cv_bridge image_transport roscpp
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories( include ${catkin_INCLUDE_DIRS} )

## Declare a cpp executable
add_executable( camera_stream src/camera_stream.cpp )
add_executable( camera_driver src/camera_driver.cpp )
add_executable( image_reader  src/image_reader.cpp  )
add_executable( image_convert  src/image_convert_node.cpp  src/ImageConvert.cpp)

## Add cmake target dependencies of the executable/library
add_dependencies( camera_stream t5_package_generate_messages_cpp )
add_dependencies( camera_driver t5_package_generate_messages_cpp )
add_dependencies( image_reader  t5_package_generate_messages_cpp )
add_dependencies( image_convert  t5_package_generate_messages_cpp )

## Specify libraries to link a library or executable target against
target_link_libraries( camera_stream ${catkin_LIBRARIES} )
target_link_libraries( camera_driver ${catkin_LIBRARIES} )
target_link_libraries( image_reader  ${catkin_LIBRARIES} )
target_link_libraries( image_convert  ${catkin_LIBRARIES} )
