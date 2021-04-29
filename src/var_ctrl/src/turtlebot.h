#pragma once

#include "geometry_msgs/Twist.h"

#include "robot.h"
#include "topic.h"
#include "types.h"
#include "utils.h"

namespace VAR_CTRL {
  class Turtlebot : public Robot<geometry_msgs::Twist> {
    public:
      Topic<PointCloud3D> depthCam;

      Turtlebot(
        ros::NodeHandle& nh,
        std::string name,
        std::string movementTopic,
        MoveController<geometry_msgs::Twist> const * controller,
        std::string depthCamTopic
      );
  };
}
