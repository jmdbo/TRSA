#include <ros/ros.h>
#include "t2_package/SetBet.h"
#include "t2_package/GameStatus.h"
#include <random>
#include <functional>
// Global vars (a necessary evil for now...)
t2_package::SetBet service_msg;
std::function<int()> generate_bet;

// TODO: Add here others global variables...
ros::ServiceClient bet_client;

// TODO: Add here the callback function that will be executed upon receiving a GameStatus message
// HINT: Callback to be called every time that a new GameStatus message is received by this node
void statusClbk( const t2_package::GameStatus &msg )
{
  switch( msg.status )
  {
    case t2_package::GameStatus::GAME_FINISHED:
      if ( msg.winner == 0 )
        ROS_INFO("I am the WINNER !!! :)");
      break;

    case t2_package::GameStatus::NEW_BET_SESSION:
      service_msg.request.bet = generate_bet();
      bet_client.call( service_msg );
      ROS_INFO("I sent my bet");
      break;

    case t2_package::GameStatus::BET_SESSION_RESULT:
      ROS_INFO( "My current score is %d" , msg.score[0] );
      break;
    }
}

int main(int argc, char **argv)
{
  ros::init( argc, argv, "ros_player" );
  ros::NodeHandle node;

  // TODO: Add here the service client to register bets
  bet_client = node.serviceClient<t2_package::SetBet>("/setBet");

  // TODO: Add here the subscriber for GameStatus messages
  ros::Subscriber sub = node.subscribe("/status", 1000, statusClbk);

  // Initialise random generator to bet
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(0,2);
  generate_bet = std::bind ( distribution, generator );
  service_msg.request.player_id = 0;
  ros::spin();
  return 0;
}
