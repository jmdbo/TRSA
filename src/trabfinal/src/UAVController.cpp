#include <ros/ros.h>
#include "trabfinal/UAVController.h"


UAVController::UAVController()
{
	UAVCtrlPub = nodeHandle.advertise<geometry_msgs::Twist>("/kelp/robot_control", 1);
	SubUavOrientation = nodeHandle.subscribe("/kelp/uav/imu", 1, &UAVController::CallbackUavOrientation, this);
	UAVPosSub = nodeHandle.subscribe("/autoland/robotPosition", 1, &UAVController::positionCallback, this);
	controllerTimer = nodeHandle.createTimer(ros::Duration(1/20), &UAVController::timerClbk, this, false, false);
	UAVImgSub = nodeHandle.subscribe("/autoland/imagePosUAV", 1, &UAVController::imgCallback, this);
	LaserSub = nodeHandle.subscribe("/autoland/laserPosUAV", 1, &UAVController::laserClbk, this);
}

/*Checks if the uav its near enough to the helipad.
  If it is, it can begin its descent. If not it's told to get nearer of the helipad center*/
void  UAVController::controller(float x, float y, float z)
{

	float radiusIncertainty = 1;

	if(x > -radiusIncertainty && x < radiusIncertainty && y > - radiusIncertainty && y < radiusIncertainty)
	{
		goHome(x, y);
		land(z);
	}
	else
	{
		goHome(x, y);
	}
}

float UAVController::fixAngle(float angle)
{

	if(angle < 0){
		angle = angle + 360;
	}
	return angle;
}
/*rotation angle which its given to the uav
  so its heading its the wanted one*/
float UAVController::rotationControl(float desiredAngle, float realAngle)
{
	float t = desiredAngle - realAngle;
	float r = t / 90;

	if(r > 1){
		return 1;
	}

	if(r < -1){
		return -1;
	}
	return r;
}
/*Control the uav speed using its distance to the helipad*/
float UAVController::distanceControl(float x, float y)
{

	float dist = sqrt(x*x + y*y) / 8;
	if(dist > 1){
		return 1;
	}
	if(dist < -1){
		return -1;
	}
	return dist;
}

/*Control the descent speed using the vertical distance between the uav and the helipad*/
float UAVController::heightControl(float z)
{

	float height = -z/10;

	if(height > 1){
		return 1;
	}

	if(height < -1){
		return -1;
	}

	return height;
}

/*Get the current heading of the uav*/
float UAVController::getUAVHeading()
{
	float fi = atan2(2 * (imuX * imuY + imuW * imuZ), (imuW * imuW - imuZ * imuZ - imuY * imuY + imuX * imuX)) * 180 / 3.14159265359;
	return fixAngle(fi);
}

/*Gets uav current coordenates and give the heading to get to helipad center*/
float UAVController::getDesiredAngle(float x, float y)
{
	float desiredAngle = atan2(y, x) * 180 / 3.1415 - 270;
	return fixAngle(desiredAngle);
}

void UAVController::CallbackUavOrientation(const sensor_msgs::Imu& msgUavOrientation)
{
	imuX = msgUavOrientation.orientation.x;
	imuY = msgUavOrientation.orientation.y;
	imuZ = msgUavOrientation.orientation.z;
	imuW = msgUavOrientation.orientation.w;
}

void UAVController::positionCallback(const trabfinal::gpsXY& msgPosition)
{
	x[0] = msgPosition.x;
	y[0] = msgPosition.y;
	uavZ = msgPosition.z;
}

void UAVController::imgCallback(const trabfinal::imagePosUAV& msgImg)
{
	x[1] = msgImg.xCenterUAV * 0.1;
	y[1] = msgImg.yCenterUAV * 0.1;
}

void UAVController::laserClbk(const trabfinal::gpsXY& msgPosition)
{
	x[2] = msgPosition.x * 0.1;
	y[2] = msgPosition.y * 0.1;
}



void UAVController::timerClbk( const ros::TimerEvent& event)
{
	int sensorId = selectSensor(uavZ);
	controller(x[sensorId], y[sensorId], uavZ);
}

/*Sends the uav to helipad center*/
void UAVController::goHome(float x, float y)
{

	float fi = getUAVHeading();
	float desiredAngle = getDesiredAngle(x, y);
	Gmt2.angular.z = rotationControl(desiredAngle, fi);

	if(fi < desiredAngle - 10 || fi > desiredAngle + 10) {
		Gmt2.linear.x = 0;
	}
	else {
		Gmt2.linear.x =  distanceControl(x, y);
	}

	UAVCtrlPub.publish(Gmt2);
}

/*Control the descent of the uav*/
void UAVController::land(float z){

	if(z >= 0.2){
		Gmt2.linear.z = heightControl(z);
	}
	else {
		Gmt2.linear.x = 0;
		Gmt2.linear.y = 0;
		Gmt2.linear.z = 0;
		Gmt2.angular.z=0;
	}
	UAVCtrlPub.publish(Gmt2);
}

/*Selects the sensor using the vertical distance between
  the uav and the helipad*/
int UAVController::selectSensor(float z)
{
	if(uavZ >= 8){
		return 0;
	}
	else if(uavZ < 8 && uavZ >= 2) {
		return 1;
	}
	else if(uavZ < 2){
		return 2;
	}
}


void UAVController::run()
{
	int q;
	for(q = 0; q < 3; q++){
		x[q] = 0;
		y[q] = 0;
	}


	controllerTimer.start();
	ros::spin();
}
