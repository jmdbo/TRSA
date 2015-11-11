#include <ros/ros.h>
#include "t4_package/ACController.h"

ACController::ACController() : m_active(false), m_desiredTemp(25), m_currTemp(0), m_mode(0), m_intensity(0)
{
    m_ac_airPub = node.advertise<t4_package::AirBeacon>("/ac_air", 1);
    m_activateAC = node.advertiseService("/set_state", &ACController::activateController, this);
    m_tempRequest = node.advertiseService("/desired_temperature", &ACController::setDesiredTemp, this);
    m_updateTimer = node.createTimer(ros::Duration(1/1.25), &ACController::timerClbk, this, false, false);
    m_tempTimeOut = node.createTimer(ros::Duration(20), &ACController::tempTimerClbk, this, false, false);
    m_temperatureSub = node.subscribe("/temperature", 20, &ACController::temperatureClbk, this);
}

void ACController::run()
{
    ros::spin();
}

bool ACController::setDesiredTemp( t4_package::DesiredTemperature::Request& req,
                                   t4_package::DesiredTemperature::Response& res)
{
    m_desiredTemp = req.temperature;
    return res.result = true;
}

bool ACController::activateController(  t4_package::ACState::Request&   req,
                                        t4_package::ACState::Response&  res)
{
  //If request active and controller not active completes activation
  //If request to deactivate and controller active completes deactivation
  //Other cases returns false
    if(req.active && !m_active){
      m_active = true;
      ROS_INFO("Starting Air Conditioner Controller!-->\n");
      m_updateTimer.start();
      m_tempTimeOut.start();
      return res.result = true;
    }else if(!req.active && m_active){
      m_active = false;
      ROS_INFO("-->Stoping Air Conditioner Controller!\n");
      m_updateTimer.stop();
      m_tempTimeOut.stop();
      return res.result = true;
    } else{
      ROS_WARN("Received Invalid Activate Command!");
      return res.result = false;
    }
}
//Defines the frequency of m_updateTimer
void ACController::setFrequency(float frequency){
  m_updateTimer.stop();
  m_updateTimer.setPeriod(ros::Duration(1/frequency));
  m_updateTimer.start();

}

void ACController::timerClbk( const ros::TimerEvent& event)
{
    float dTemp = m_currTemp - m_desiredTemp;
    t4_package::AirBeacon msg;
    //Verifies the temperature range
    if(dTemp>4.5 || dTemp<-4.5){
        if(m_intensity != 3){
            m_intensity = 3;
            ACController::setFrequency(5);
        }
    }else if (dTemp>1.5 || dTemp<-1.5){
        if(m_intensity != 2){
            m_intensity = 2;
            ACController::setFrequency(2.5);
        }
    }else if (dTemp!=0){
        if(m_intensity != 1){
            m_intensity = 1;
            ACController::setFrequency(1.25);
        }
    } else if(m_intensity != 0){
        m_intensity = 0;
        ACController::setFrequency(1.25);
    }
    //Verifies the AC Mode
    if(dTemp>0){
      msg.mode = t4_package::AirBeacon::COOL;
    }else if(dTemp<0){
      msg.mode = t4_package::AirBeacon::HEAT;
    } else{
      msg.mode = t4_package::AirBeacon::IDLE;
    }
    //Prints the current state
    ROS_INFO("------------------------------------------------------");
    ROS_INFO("Current Temperature: %f C", m_currTemp);
    ROS_INFO("Desired Temperature: %f C", m_desiredTemp);
    switch (msg.mode) {
      case t4_package::AirBeacon::HEAT:
          ROS_INFO("AC Mode: HEAT");
          break;
      case t4_package::AirBeacon::COOL:
          ROS_INFO("AC Mode: COOL");
          break;
      case t4_package::AirBeacon::IDLE:
          ROS_INFO("AC Mode: IDLE");
          break;
      default:
          ROS_WARN("Invalid mode!");
          msg.mode = t4_package::AirBeacon::IDLE;
    }
    switch (m_intensity) {
      case 0:
          ROS_INFO("Intensity: None");
          break;
      case 1:
          ROS_INFO("Intensity: Minimum");
          break;
      case 2:
          ROS_INFO("Intensity: Medium");
          break;
      case  3:
          ROS_INFO("Intensity: Maximum");

    }
    ROS_INFO("------------------------------------------------------");
    //Finally sends the message
    m_ac_airPub.publish(msg);

}

void ACController::tempTimerClbk( const ros::TimerEvent& event)
{
  ROS_WARN("No temperature info received for 20 seconds -> shutting down AC!");
  m_active = false;
  m_updateTimer.stop();
  m_tempTimeOut.stop();
}

void ACController::temperatureClbk( const sensor_msgs::Temperature& msg)
{
    if(msg.header.frame_id=="ac"){
      m_currTemp = msg.temperature;
      m_tempTimeOut.stop();
      m_tempTimeOut.start();
    }
}
