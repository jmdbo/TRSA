
#ifndef _GAME_ENGINE_H_
#define _GAME_ENGINE_H_

#include <ros/ros.h>

#include "t2_package/SetBet.h"
#include "t2_package/Activate.h"
#include "t2_package/GameStatus.h"


class GameEngine
{
	public:

	    GameEngine();

	    ~GameEngine();

	    void run();

	private:


	    unsigned int m_savedBet;
	    unsigned int m_rounds;

	    bool m_active;

			const int TIMEOUT = 10;

	    ros::NodeHandle node;

	    int m_rulesMatrix[3][3];  // Matrix with game rules

	    unsigned int m_playerScore[2];

	    ros::ServiceServer m_setBet;
	    ros::ServiceServer m_activateGame;
	    ros::Publisher m_resultPub;
			ros::Timer m_sessionTimer;

	    int m_playerBetted;

	    void reset();

	    bool registerBet( t2_package::SetBet::Request  &req,
                          t2_package::SetBet::Response &res );

	    bool activateEngine( t2_package::Activate::Request  &req,
	    	                 t2_package::Activate::Response &res );

	    void timerClbk( const ros::TimerEvent& event );

	    const char* decodeBet( unsigned int bet );
};

#endif
