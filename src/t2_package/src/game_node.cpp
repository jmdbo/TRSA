
#include <ros/ros.h>
#include "t2_package/GameEngine.h"


int main(int argc, char **argv)
{
    ros::init( argc, argv, "game_engine" );

    ROS_INFO(" ");
    ROS_INFO("##########################################");
    ROS_INFO("#                                        #");
    ROS_INFO("#           ROCK-PAPER-SCISSORS          #");
    ROS_INFO("#                                        #");
    ROS_INFO("##########################################");
    ROS_INFO(" ");
    ROS_INFO("Place your bets by calling the service \\set_bet");
    ROS_INFO("Max. players allowed: 2");
    ROS_INFO(" ");

    GameEngine game;

    game.run();

    return 0;
}
