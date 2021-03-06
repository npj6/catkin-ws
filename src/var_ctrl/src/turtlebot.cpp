#include "turtlebot.h"

namespace VAR_CTRL {
  Turtlebot::Turtlebot(
    ros::NodeHandle& nh,
    std::string name,
    std::string movementTopic,
    const ControllerIFace<TwistMove> * controller,
    std::string depthCamTopic
  ) :
    Robot(nh, name, movementTopic, controller),
    depthCam(nh, topic_name(name, depthCamTopic))
  { }
}
