#include <ros/ros.h>
#include "trabfinal/laserControl.h"



laserControl::laserControl()
: m_currHeight(100), m_dataCurrent(false), m_maxAngle(1.57), m_minAngle(0.0), m_currAngle(0), m_lastSeq(0), m_increment(true)
{
    m_servoControl = node.serviceClient<kelp_ros::ServoControl>("/kelp/uav/laser_scan/servo_control");
    m_UAVlocation = node.subscribe( "/kelp/uav/gps", 20, &laserControl::gpsClbk, this );
    m_JointState = node.subscribe( "/kelp/uav/laser_scan/joint_state", 20, &laserControl::jointClbk, this);
    //m_timerServo = node.createTimer(ros::Duration(1.0), &laserControl::timerClbk, this, false, true);
}




void laserControl::run()
{
    ros::Rate rate(20.0);
    while ( ros::ok() )
    {
        ros::spinOnce();
        kelp_ros::ServoControl srv;
        ROS_INFO("Max Angle: %f", m_maxAngle);
        ROS_INFO("Min Angle: %f", m_minAngle);
        ROS_INFO("Current Angle: %f", m_currAngle);
        ROS_INFO("Increment: %d", m_increment);
        //If the joint is between the min and max angles increment or decrement gradually
        if( m_currAngle < m_maxAngle && m_currAngle> m_minAngle ){
          srv.request.axis[0]=false;
          srv.request.axis[1]=true;
          srv.request.axis[2]=false;
          if(m_increment)
            srv.request.angle = +0.01;
          else
            srv.request.angle = -0.01;
        }else if (m_currAngle>=m_maxAngle){
          //if max limit reached start decrementing
          m_increment = false;
          srv.request.axis[0]=false;
          srv.request.axis[1]=true;
          srv.request.axis[2]=false;
          //resets laser to maxAngle - 0.01;
          srv.request.angle = m_maxAngle - m_currAngle - 0.01;
        } else if (m_currAngle<=m_minAngle){
          //if min limit reached start incrementing
          m_increment = true;
          srv.request.axis[0]=false;
          srv.request.axis[1]=true;
          srv.request.axis[2]=false;
          ///resets laser to minAngle + 0.01
          srv.request.angle = m_minAngle - m_currAngle +0.01;
        }
        if(!m_servoControl.call(srv)){
          ROS_WARN("Error calling servo_control!");
        }
        rate.sleep();
    }
}


void laserControl::gpsClbk ( const sensor_msgs::NavSatFix& msg )
{
  double centerAngle=0;
  if(msg.status.status >= 0){
      m_currHeight = msg.altitude;
      if(m_currHeight>5){
        m_minAngle = 0;
        m_maxAngle = 0;
      }else if(m_currHeight> 1){
        //Calculations in the case that the UAV is above the laser
        centerAngle = atan2(1, m_currHeight-1);
        m_minAngle = centerAngle - 20 * (3.14/180);
        m_maxAngle = centerAngle + 20 * (3.14/180);
      } else if (m_currHeight==1){
        //In the remote eventuality that the UAV is exactly at the level of the laser
        centerAngle = 3.14/2;
        m_minAngle = centerAngle - 20 * (3.14/180);
        m_maxAngle = centerAngle + 20 * (3.14/180);
      }
      else{
        //Calculations in the case that the UAV is below the laser
        centerAngle = atan2(1-m_currHeight, 1);
        centerAngle+= 1.570796327;
        m_minAngle = centerAngle - 20 * (3.14/180);
        m_maxAngle = centerAngle + 20 * (3.14/180);
      }

  }
}
//Gets the current joint position
void laserControl::jointClbk( const sensor_msgs::JointState& msg)
{
  if(msg.header.seq> m_lastSeq){
    m_currAngle = msg.position[1];
  }
}
