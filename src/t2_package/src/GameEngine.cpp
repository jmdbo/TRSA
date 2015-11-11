
#include "t2_package/GameEngine.h"


GameEngine::GameEngine() : m_playerBetted(-1), m_rounds(0), m_active(false)
{
    m_setBet = node.advertiseService( "/setBet", &GameEngine::registerBet, this);
    m_activateGame = node.advertiseService( "/activate", &GameEngine::activateEngine, this);
    m_sessionTimer = node.createTimer( ros::Duration(TIMEOUT), &GameEngine::timerClbk, this, false, false );
    m_resultPub = node.advertise<t2_package::GameStatus>("/status", 1);

    // Initialise game rules
    m_rulesMatrix[0][0] =  0;
    m_rulesMatrix[0][1] =  1;
    m_rulesMatrix[0][2] = -1;
    m_rulesMatrix[1][0] = -1;
    m_rulesMatrix[1][1] =  0;
    m_rulesMatrix[1][2] =  1;
    m_rulesMatrix[2][0] =  1;
    m_rulesMatrix[2][1] = -1;
    m_rulesMatrix[2][2] =  0;

    m_playerScore[0] = 0;
    m_playerScore[1] = 0;

}



GameEngine::~GameEngine(){};



void GameEngine::reset()
{
    m_sessionTimer.stop();
    m_playerBetted = -1;
    m_playerScore[0] = 0;
    m_playerScore[1] = 0;
    m_rounds = 0;
}



void GameEngine::run()
{
    ros::spin();
}




bool GameEngine::registerBet( t2_package::SetBet::Request  &req, t2_package::SetBet::Response &res )
{
    if ( !m_active )
        return res.result = false;
    // Check for invalid player ID
    if (req.player_id > 1)
        return res.result = false;
    // Check for invalid bet
    if (req.bet > 2)
        return res.result = false;

    // Check if it is the first bet of the current session
    if ( m_playerBetted == -1 )
    {
        m_playerBetted = req.player_id;
        m_savedBet = req.bet;  // Save bet

        ROS_INFO( "Player %d placed the first bet", m_playerBetted );
        ROS_WARN( "The bet session will end in %d seconds.", TIMEOUT);
        m_sessionTimer.start();

    }
    else
    {
        // if receive a new bet of the same player, update his bet
        if ( m_playerBetted == req.player_id )
        {
            m_savedBet = req.bet;
            ROS_INFO( "Player %d placed a new bet", m_playerBetted );
        }
        else  // Received bets from the two players
        {

            ROS_INFO("Player %d placed a bet", req.player_id);
            m_sessionTimer.stop();
            t2_package::GameStatus msg;

            switch ( m_rulesMatrix[m_savedBet][req.bet] )
            {
                case -1:
                    ROS_INFO( "Player %d is the winner!", req.player_id );
                    m_playerScore[req.player_id]++;
                    msg.winner = req.player_id;
                    break;

                case 0:
                    ROS_INFO( "Tie! No winner this time" );
                    msg.winner = -1;
                    break;

                case 1:
                    ROS_INFO( "Player %d is the winner!", m_playerBetted );
                    m_playerScore[m_playerBetted]++;
                    msg.winner = m_playerBetted;
                    break;
            }

            // Broadcast session result
            msg.status = t2_package::GameStatus::BET_SESSION_RESULT;
            msg.score[0] = m_playerScore[0];
            msg.score[1] = m_playerScore[1];
            m_resultPub.publish( msg );

            // update control logic
            m_rounds++;
            m_playerBetted = -1;

            if (m_rounds == 5)
            {
                // Broadcast end game message
                t2_package::GameStatus msg;
                msg.status = t2_package::GameStatus::GAME_FINISHED;

                if ( m_playerScore[0] > m_playerScore[1] )
                {
                    msg.winner = 0;
                    ROS_INFO("WINNER is %d", msg.winner);
                }
                else if (m_playerScore[0] < m_playerScore[1])
                {
                    msg.winner = 1;
                    ROS_INFO("WINNER is %d", msg.winner);
                }
                else
                    msg.winner = -1;

                m_resultPub.publish( msg );

               reset();
            }

            // Broadcast new session bet
            ROS_INFO( " " );
            ROS_WARN( "===========================" );
            ROS_WARN( "=        Round #%d        =", m_rounds+1 );
            ROS_WARN( "===========================" );
            ROS_INFO( " " );

            msg.status = t2_package::GameStatus::NEW_BET_SESSION;
            m_resultPub.publish( msg );
        }

    }

    return res.result = true;
}


bool GameEngine::activateEngine( t2_package::Activate::Request  &req,
                                 t2_package::Activate::Response &res )
{
    m_active = req.active;

    if ( !m_active )
        reset();
    else
    {
        // Broadcast new bet session
        t2_package::GameStatus msg;
        msg.status = t2_package::GameStatus::NEW_BET_SESSION;
        m_resultPub.publish( msg );
    }

    return res.result = true;
}

void GameEngine::timerClbk ( const ros::TimerEvent& event )
{
    m_playerBetted = -1;
    m_sessionTimer.stop();
    ROS_WARN( "The bet session expired... Broadcasting a new bet session" );
    t2_package::GameStatus msg;
    msg.status = t2_package::GameStatus::NEW_BET_SESSION;
    m_resultPub.publish( msg );
}


const char* GameEngine::decodeBet( unsigned int bet )
{
    switch( bet )
    {
        case 0:
            return "ROCK";

        case 1:
            return "SCISSOR";

        case 2:
            return "PAPER";

        default:
            return "UNKNOWN";
    }
}
