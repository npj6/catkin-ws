#pragma once

#include <string>
#include <vector>

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"


namespace VAR_CTRL {
  class Controller {
    protected:
      ros::Publisher movement;

      double forward_speed, rotation_speed;

      void move(void);

      virtual void decision(void) = 0;

    public:
      Controller(ros::NodeHandle& nh, std::string robot_name);

      void iterate(void);
  };
}
