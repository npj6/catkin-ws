#pragma once

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <string>


/*
      ejemplo suscripciones
      ros::Subscriber trasera1;
      ros::Subscriber trasera2;
      ros::Subscriber delantera;
      laserSub = nh.subscribe("base_scan", 1, &Wander::commandCallback, this);
      void commandCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
*/

namespace VAR_CTRL {
  class Controller {
    protected:
      ros::Publisher movement;

      double forward_speed;
      double rotation_speed;

    public:
      Controller(ros::NodeHandle& nh, std::string robot_name);
      void loop(void);
  };
}
