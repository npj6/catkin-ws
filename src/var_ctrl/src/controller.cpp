#include "controller.h"

/*DepthInfo, incluir por composicion, modulos de informacion a añadir, controller solo controla*/

namespace VAR_CTRL {
  Controller::Controller(ros::NodeHandle& nh, std::string robot_name, std::string sensors[]) {
    forward_speed=1.0;
    rotation_speed=0.0;
    // segundo parametro: si acumulamos varios mensajes, solo el último será enviado.
    movement = nh.advertise<geometry_msgs::Twist>("/"+robot_name+"/mobile_base/commands/velocity", 1);

    Info info(nh, robot_name, sensors);
    sources.push_back(info);
  }

  void Controller::loop(void) {
    ros::Rate rate(10); // frecuencia del bucle en hertzios (normalmente 100)
    while (ros::ok()) {
      move();
      ros::spinOnce(); // procesar llamadas pendientes (callBacks de suscripciones)
      rate.sleep();
    }
  }

  void Controller::move(void) {
    geometry_msgs::Twist msg;
    msg.linear.x = forward_speed;
    msg.angular.z = rotation_speed;
    movement.publish(msg);
  }

}
