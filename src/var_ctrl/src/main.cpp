#include "controller.h"
#include "ros/ros.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "var_ctrl");
  ros::NodeHandle nh;
  VAR_CTRL::Controller controller(nh, "robot1");
  controller.loop();
  return 0;
};
