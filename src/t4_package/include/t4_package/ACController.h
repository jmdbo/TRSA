#ifndef _ACCONTROLLER_H_
#define _ACCONTROLLER_H_

#include <ros/ros.h>
#include <sensor_msgs/Temperature.h>

#include <t4_package/DesiredTemperature.h>
#include <t4_package/ACState.h>
#include <t4_package/AirBeacon.h>

class ACController
{
    public:

        ACController();
        virtual ~ACController(){};

        void run();

    private:

        ros::NodeHandle node;

        float m_desiredTemp;
        float m_currTemp;
        int m_mode;
        int m_intensity;
        bool m_active;

        /* Timer that controls the frequency of the mensages */
        ros::Timer m_updateTimer;
        /* Timer that shuts the AC Controller in case of no messages from Thermometer */
        ros::Timer m_tempTimeOut;

        /* Service Clients & Servers */
        ros::ServiceServer m_activateAC;
        ros::ServiceServer m_tempRequest;

        /* Message Publishers & Subscribers */
        ros::Subscriber m_temperatureSub;
        ros::Publisher m_ac_airPub;

        bool setDesiredTemp( t4_package::DesiredTemperature::Request& req,
           t4_package::DesiredTemperature::Response& res);
        bool activateController( t4_package::ACState::Request& req,
          t4_package::ACState::Response& res);
        void setFrequency(float frequency);
        void timerClbk( const ros::TimerEvent& event);
        void tempTimerClbk(const ros::TimerEvent& event);
        void temperatureClbk(const sensor_msgs::Temperature& msg);

};


#endif
