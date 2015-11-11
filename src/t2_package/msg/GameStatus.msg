# Constant Definition for game status
uint8 NEW_BET_SESSION = 0
uint8 BET_SESSION_RESULT = 1
uint8 GAME_FINISHED = 2

uint8 status
uint8[2] score # score[0] = ROS Player; score[1] = Human Player
int8 winner # -1 = Not defined (tie); 0 = ROS Player; 1 = Human Player
