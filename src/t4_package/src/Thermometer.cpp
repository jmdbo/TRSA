
#include <ros/ros.h>
#include "t4_package/Thermometer.h"



Thermometer::Thermometer()

    : m_defaultTemp(25.0), m_currTemp(25.0), m_tickCtr(0)

{
    m_tempSrv = node.advertiseService("/set_temperature", &Thermometer::setTemperature, this);

    m_airBeaconSub = node.subscribe( "/ac_air", 20, &Thermometer::airBeaconClbk, this );

    m_sensor_tempPub = node.advertise< sensor_msgs::Temperature >( "/temperature", 1 );

    m_timerRestore = node.createTimer(ros::Duration(6.0), &Thermometer::restoreClbk, this, false, true);
}




void Thermometer::run()
{
    ros::Rate rate(10.0);

    while ( ros::ok() )
    {
        ros::spinOnce();

        ROS_INFO( "Room Temperature: %f", m_currTemp );

        sensor_msgs::Temperature tempMsg;
        tempMsg.header.frame_id = "ac";
        tempMsg.header.stamp = ros::Time::now();
        tempMsg.temperature = m_currTemp;
        m_sensor_tempPub.publish(tempMsg);

        rate.sleep();
    }
}



/* Callback Implementation */

bool Thermometer::setTemperature( t4_package::SetTemperature::Request&  req,
                                  t4_package::SetTemperature::Response& res  )
{
   m_defaultTemp = m_currTemp = req.temperature;
   return res.result = true;
}



void Thermometer::airBeaconClbk ( const t4_package::AirBeacon& msg )
{
    switch (msg.mode)
    {
        case t4_package::AirBeacon::HEAT:

            if ( m_tickCtr++ == 4 )
            {
                m_currTemp += 0.5;
                m_tickCtr = 0;
            }
            break;

        case t4_package::AirBeacon::COOL:
            if ( m_tickCtr++ == 4 )
            {
                m_currTemp -= 0.5;
                m_tickCtr = 0;
            }
            break;

        case t4_package::AirBeacon::IDLE:
            m_tickCtr = 0;
            break;

        default:
            ROS_WARN("Received incorrect mode on AirBeacon message.");
    }
}



void Thermometer::restoreClbk ( const ros::TimerEvent& event )
{
    if ( m_defaultTemp != m_currTemp )
    {
        m_currTemp += ( ( m_defaultTemp > m_currTemp ) ? 0.25 : -0.25 );
    }
}
