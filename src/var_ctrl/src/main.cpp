#include <vector>
#include <string>

#include <iostream>
#include <cstdlib>

#include "robot.h"
#include "turtlebot.h"

#include "controller_i_face.h"
#include "types.h"
#include "test_controller.h"

#include "ros/ros.h"

void loop(std::vector<VAR_CTRL::RobotIFace*> robots);

void usage(void);

int main(int argc, char **argv) {
  ros::init(argc, argv, "var_ctrl");
  ros::NodeHandle nh;
  std::vector<VAR_CTRL::RobotIFace*> robots;

  VAR_CTRL::ControllerIFace<VAR_CTRL::TwistMove> * controller;
  VAR_CTRL::TestController testController;

  if (argc != 2) { usage(); }

  if ((std::string) argv[1] == "TestController") {
    controller = &testController;
  } else {
    usage();
  }

  VAR_CTRL::Turtlebot robot(nh, "", "mobile_base/commands/velocity", controller, "camera/depth/points");
  robots.push_back(&robot);

  loop(robots);
  return 0;
};

// allows multiples robots, separates program flow from Robot class
void loop(std::vector<VAR_CTRL::RobotIFace*> robots) {
  ros::Rate rate(10); // frecuencia del bucle en hertzios (normalmente 100)
  while (ros::ok()) {
    ros::spinOnce(); // procesar llamadas pendientes (callBacks de suscripciones)
    for(std::size_t i=0; i<robots.size(); ++i) {
      robots[i]->cycle();
    }
    rate.sleep();
  }
}

void usage(void) {
  std::cout << "Usage:" << std::endl;
  std::cout << "rosrun var_ctrl var_ctrl controller" << std::endl;
  std::cout << "Controller types:" << std::endl;
  std::cout << "- TestController" << std::endl;
  exit(0);
}
