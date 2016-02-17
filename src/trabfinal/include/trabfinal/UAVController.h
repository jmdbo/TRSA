#ifndef _UAVCONTROLLER_H_
#define _UAVCONTROLLLER_H_

#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/Twist.h>
#include <trabfinal/gpsXY.h>
#include <trabfinal/imagePosUAV.h>

class UAVController{
public:

	UAVController();
	~UAVController(){};

	void run();

private:

	/* Common Variables */
	ros::NodeHandle nodeHandle;
	geometry_msgs::Twist Gmt2;
	int inicialHeightCtrl; //0 - First time entering, 1 - Not the first time entering
	float imuX, imuY, imuZ, imuW; //Stores Uav orientation values
	float x[3], y[3]; // 0 : Stores the position given by GPS, 1 :Stores the position given by the image, 2 :Stores the position given by laser
	float uavZ, initialHeight; //Stores the height of the Uav and the first height to be seen

	/* Message Publishers & Subscribers */
	ros::Publisher UAVCtrlPub; //Publisher Control UAV
	ros::Subscriber UAVPosSub; // Subscritor GPS
	ros::Subscriber SubUavOrientation; //Subscritor IMU
	ros::Subscriber UAVImgSub; //Subscritor Imagem

	/* Timer that starts the controller */
	ros::Timer controllerTimer;

	/* Received Messages Callbacks */
	void CallbackUavOrientation( const sensor_msgs::Imu& msgUavOrientation);
	void imgCallback(const trabfinal::imagePosUAV& msgImg);
	void positionCallback(const trabfinal::gpsXY& msgPosition);
	void timerClbk( const ros::TimerEvent& event);

	/* Change angle range from -180 -> 180 to 0 -> 360 */
	float fixAngle(float angle);
	/* Change rotation speed  */
	float rotationControl(float desiredAngle, float realAngle);
	/* Change x axis speed */
	float distanceControl(float x, float y);
	/* Change z axis speed */
	float heightControl(float z);
	/* Get the right angle from the Uav orientation */
	float getUAVHeading();
	/* Get the angle between the Uav and the Helipad */
	float getDesiredAngle(float x, float y);
	/*  Control Uav's position and behaviour */
	void controller(float x, float y, float z);
	/* Go to the Helipad */
	void goHome(float x, float y);
	/* Land on the Helipad */
	void land(float z);
	/* Select sensor based on height */
	int selectSensor(float z);
};
#endif
