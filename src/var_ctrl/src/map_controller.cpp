#include "map_controller.h"

namespace VAR_CTRL {
  TwistMove MapController::doTypedDecision(const Turtlebot * robot) const {
    //basic control
    TwistMove msg;
    std::cout << "control the bot with wasd+Enter (e+Enter to exit)" << std::endl;
    std::string line;
    getline(std::cin, line);
    if(0 < line.size()) {
      switch(line[0]) {
        case 'w':
          msg.linear.x = 1.0;
          msg.angular.z = 0.0;
          break;
        case 'a':
          msg.linear.x = 0.0;
          msg.angular.z = 1.0;
          break;
        case 's':
          msg.linear.x = -1.0;
          msg.angular.z = 0.0;
          break;
        case 'd':
          msg.linear.x = 0.0;
          msg.angular.z = -1.0;
          break;
        case 'e':
          std::exit(0);
        default:
          msg.linear.x = 0.0;
          msg.angular.z = 0.0;
      }
    }
    //cleans the last command
    std::cout << "\033[1A\033[1K\033[1A" << std::flush;
    return msg;
  }
}
