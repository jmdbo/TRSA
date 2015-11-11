#ifndef _THERMOMETER_H_
#define _THERMOMETER_H_

#include <string>
#include <map>

#include <ros/ros.h>
#include <std_msgs/Float32.h>
#include <sensor_msgs/Temperature.h>

#include "t4_package/AirBeacon.h"
#include "t4_package/SetTemperature.h"




class Thermometer
{

    public:

        Thermometer();
        virtual ~Thermometer(){};

        void run();

    private:

        ros::NodeHandle node;

        float m_defaultTemp;
        float m_currTemp;

        unsigned int m_tickCtr;

        ros::Timer m_timerRestore;

        /* Service Clients & Servers */
        ros::ServiceServer m_tempSrv;

        /* Message Publishers & Subscribers */
        ros::Subscriber m_airBeaconSub;
        ros::Publisher m_sensor_tempPub;

        /* Service, Message & Other Callbacks */
        bool setTemperature( t4_package::SetTemperature::Request& req,
                             t4_package::SetTemperature::Response& res);

        void airBeaconClbk ( const t4_package::AirBeacon& msg );
        void restoreClbk   ( const ros::TimerEvent& );
};

#endif
