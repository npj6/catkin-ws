#pragma once

#include "robot.h"

#include "types.h"
#include "utils.h"

#include "topic.h"

namespace VAR_CTRL {
  class Turtlebot : public Robot<TwistMove> {
    public:
      Topic<PointCloud3D> depthCam;

      Turtlebot(
        ros::NodeHandle& nh,
        std::string name,
        std::string movementTopic,
        const ControllerIFace<TwistMove> * controller,
        std::string depthCamTopic
      );
  };
}
