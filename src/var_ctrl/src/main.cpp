#include <vector>
#include <string>

#include "test_controller.h"
#include "map_controller.h"

#include "robot.h"
#include "turtlebot.h"

#include "ros/ros.h"

void loop(std::vector<VAR_CTRL::RobotIFace*> robots);

int main(int argc, char **argv) {
  ros::init(argc, argv, "var_ctrl");
  ros::NodeHandle nh;
  std::vector<VAR_CTRL::RobotIFace*> robots;

  VAR_CTRL::MapController controller;
  VAR_CTRL::Turtlebot robot(nh, "", "mobile_base/commands/velocity", &controller, "camera/depth/points");
  robots.push_back(&robot);

  loop(robots);
  return 0;
};

//allows multiples robots, separates program flow from Robot class
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
