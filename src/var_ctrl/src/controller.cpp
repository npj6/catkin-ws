#include "controller.h"

/*DepthInfo, incluir por composicion, modulos de informacion a añadir, controller solo controla*/

namespace VAR_CTRL {
  Controller::Controller(ros::NodeHandle& nh, std::string robot_name) {
    forward_speed=1.0;
    rotation_speed=0.0;
    // segundo parametro: si acumulamos varios mensajes, solo el último será enviado.
    movement = nh.advertise<geometry_msgs::Twist>("/"+robot_name+"/mobile_base/commands/velocity", 1);
    depth_pc2[front] = nh.subscribe(
      "/"+robot_name+"/camera/depth/points", 1, &Controller::depth_pc2_callback<front>, this
    );
    depth_pc2[back1] = nh.subscribe(
      "/"+robot_name+"/trasera1/trasera1/depth/points", 1, &Controller::depth_pc2_callback<back1>, this
    );
    depth_pc2[back2] = nh.subscribe(
      "/"+robot_name+"/trasera2/trasera2/depth/points", 1, &Controller::depth_pc2_callback<back2>, this
    );
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

  void Controller::depth_pc2_callback(const sensor_msgs::PointCloud2::ConstPtr& msg, Cam camera) {
    std::cout << "CALLBACK from " << camera << std::endl;
  }
}
