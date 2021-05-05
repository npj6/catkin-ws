#include "utils.h"

namespace VAR_CTRL {

  std::string topic_name(std::string robot, std::string topic) {
    return (robot.empty()?"":"/")+robot+"/"+topic;
  }

}
