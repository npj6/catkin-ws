#include "utils.h"

namespace VAR_CTRL {

  std::string topic_name(std::string robot, std::string device, std::string topic) {
    return robot+(robot.empty()?"":"/")+device+"/"+topic;
  }

}
