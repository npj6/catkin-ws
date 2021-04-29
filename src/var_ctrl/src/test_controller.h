#pragma once
#include "controller.h"

#include "turtlebot.h"

#include "geometry_msgs/Twist.h"

namespace VAR_CTRL {

  class TestController : public Controller<geometry_msgs::Twist, Turtlebot> {
    protected:
      geometry_msgs::Twist doTypedDecision(Turtlebot const * robot) const;

  };

}

