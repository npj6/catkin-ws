#include "controller.h"

#include <iostream>

/*DepthInfo, incluir por composicion, modulos de informacion a añadir, controller solo controla*/

namespace VAR_CTRL {
  Controller::Controller(ros::NodeHandle& nh, std::string robot_name, std::string sensors[]) {
    forward_speed=1.0;
    rotation_speed=0.0;
    // segundo parametro: si acumulamos varios mensajes, solo el último será enviado.
    movement = nh.advertise<geometry_msgs::Twist>("/"+robot_name+"/mobile_base/commands/velocity", 1);

    sources[0].initialize(nh, robot_name, sensors);
  }

  void Controller::loop(void) {
    ros::Rate rate(10); // frecuencia del bucle en hertzios (normalmente 100)
    while (ros::ok()) {
      ros::spinOnce(); // procesar llamadas pendientes (callBacks de suscripciones)
      decision();
      move();
      rate.sleep();
    }
  }

  void Controller::decision(void) {
    //modify forward and rotation speeds
    //access source information through:
    //  sources[n].get_size(Cam)
    //  sources[n].get_data(Cam, uint)
  }

  void Controller::move(void) {
    geometry_msgs::Twist msg;
    msg.linear.x = forward_speed;
    msg.angular.z = rotation_speed;
    movement.publish(msg);
  }

}
