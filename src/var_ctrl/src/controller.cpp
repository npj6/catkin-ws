#include "controller.h"

namespace VAR_CTRL {
  Controller::Controller(ros::NodeHandle& nh, std::string robot_name) {
    forward_speed=0.0;
    rotation_speed=0.0;
    // segundo parametro: si acumulamos varios mensajes, solo el último será enviado.
    movement = nh.advertise<geometry_msgs::Twist>(topic_name(robot_name, "mobile_base", "commands/velocity"), 1);
  }

  void Controller::iterate(void) {
     decision();
     move();
  }

  void Controller::move(void) {
    geometry_msgs::Twist msg;
    msg.linear.x = forward_speed;
    msg.angular.z = rotation_speed;
    movement.publish(msg);
  }

}
