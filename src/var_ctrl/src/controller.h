#pragma once

#include <string>
#include <vector>

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

#include "info.h"


namespace VAR_CTRL {
  class Controller {
    protected:
      ros::Publisher movement;

      Info sources[1];

      double forward_speed, rotation_speed;

      void move(void);

      void decision(void);

    public:
      Controller(ros::NodeHandle& nh, std::string robot_name, std::string sensors[]);
      void loop(void);
  };
}
