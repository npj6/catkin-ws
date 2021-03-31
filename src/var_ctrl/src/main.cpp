#include "controller.h"
#include "ros/ros.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "var_ctrl");
  ros::NodeHandle nh;
  std::string sensors[] = {"camera", "trasera1/trasera1", "trasera2/trasera2"};
  VAR_CTRL::Controller controller(nh, "robot1", sensors);
  controller.loop();
  return 0;
};
