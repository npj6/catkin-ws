#include "test_controller.h"

namespace VAR_CTRL {
  TestController::TestController(ros::NodeHandle& nh, std::string robot_name, std::string sensors[]) :
    Controller(nh, robot_name),
    source(nh, robot_name, sensors, "depth/points") { }

  void TestController::decision(void) {
    forward_speed = 1.0;
    rotation_speed = 0.0;
  }
}
