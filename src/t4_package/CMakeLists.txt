cmake_minimum_required(VERSION 2.8.3)
project( t4_package )

## Find catkin macros and libraries
find_package( catkin REQUIRED COMPONENTS roscpp std_msgs message_generation )
SET (CMAKE_C_FLAGS "-std=c++11")
SET (CMAKE_CXX_FLAGS "-std=c++11")

################################################
## Declare ROS messages, services and actions ##
################################################

## Generate messages in the 'msg' folder
add_message_files( FILES AirBeacon.msg )

## Generate services in the 'srv' folder
add_service_files( 	FILES
										SetTemperature.srv
										DesiredTemperature.srv
										ACState.srv )

## Generate added messages and services with any dependencies listed here
generate_messages( DEPENDENCIES std_msgs )


###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
catkin_package( INCLUDE_DIRS include CATKIN_DEPENDS roscpp std_msgs )


###########
## Build ##
###########

## Specify additional locations of header files
include_directories( include ${catkin_INCLUDE_DIRS} )

## Declare a C++ executable
add_executable( thermometer    src/thermometer_node.cpp  src/Thermometer.cpp  )
add_executable( ac_controller src/ac_controller_node.cpp src/ACController.cpp )

## Add cmake target dependencies of the executable

add_dependencies( thermometer   ${${PROJECT_NAME}_EXPORTED_TARGETS}
								${catkin_EXPORTED_TARGETS} )
add_dependencies( ac_controller   ${${PROJECT_NAME}_EXPORTED_TARGETS}
								${catkin_EXPORTED_TARGETS} )

## Specify libraries to link a library or executable target against
target_link_libraries( thermometer   ${catkin_LIBRARIES} )
target_link_libraries( ac_controller ${catkin_LIBRARIES} )
