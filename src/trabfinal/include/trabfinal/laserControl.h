#ifndef _THERMOMETER_H_
#define _THERMOMETER_H_

#include <string>
#include <map>

#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>
#include <sensor_msgs/JointState.h>

#include "kelp_ros/ServoControl.h"


class laserControl
{

    public:

        laserControl();
        virtual ~laserControl(){};

        void run();
    private:

        ros::NodeHandle node;

        float m_currHeight;
        double m_currAngle;
        double m_maxAngle;
        double m_minAngle;
        bool m_dataCurrent;
        bool m_increment;

        uint32_t m_lastSeq;

        ros::Timer m_timerServo;

        /* Service Clients & Servers */
        ros::ServiceClient m_servoControl;

        /* Message Publishers & Subscribers */
        ros::Subscriber m_UAVlocation;
        ros::Subscriber m_JointState;

        /* Service, Message & Other Callbacks */

      //  void airBeaconClbk ( const t4_package::AirBeacon& msg );
        void gpsClbk   ( const sensor_msgs::NavSatFix& );
        void jointClbk( const sensor_msgs::JointState& );

};

#endif
