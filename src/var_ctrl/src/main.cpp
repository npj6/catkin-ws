#include <vector>

#include "test_controller.h"
#include "types.h"

#include "ros/ros.h"

void loop(std::vector<VAR_CTRL::Controller*> controllers);

int main(int argc, char **argv) {
  ros::init(argc, argv, "var_ctrl");
  ros::NodeHandle nh;
  std::vector<VAR_CTRL::Controller*> controllers;

  std::string turtlebot_sensors[VAR_CTRL::TurtlebotCams::NUM] = {"camera", "trasera1/trasera1", "trasera2/trasera2"};

  VAR_CTRL::TestController controller(nh, "robot1", turtlebot_sensors);
  controllers.push_back(&controller);

  VAR_CTRL::TestController controller2(nh, "robot2", turtlebot_sensors);
  controllers.push_back(&controller2);

  loop(controllers);
  return 0;
};

//allows multiples controllers, separates program flow from Controller class
void loop(std::vector<VAR_CTRL::Controller*> controllers) {
  ros::Rate rate(10); // frecuencia del bucle en hertzios (normalmente 100)
  while (ros::ok()) {
    ros::spinOnce(); // procesar llamadas pendientes (callBacks de suscripciones)
    for(std::size_t i=0; i<controllers.size(); ++i) {
      controllers[i]->iterate();
    }
    rate.sleep();
  }
}
