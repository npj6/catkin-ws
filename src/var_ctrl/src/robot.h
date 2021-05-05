#pragma once

#include "ros/ros.h"

#include "robot_i_face.h"
#include "controller_i_face.h"
#include "utils.h"

#include <string>

namespace VAR_CTRL {

  //forward declaration of move_controller
  template<class T>
    class ControllerIFace;

  template <class MoveMsg>
    class Robot : public RobotIFace {
 
      protected:
        //Robot name
        std::string name;
        //Movement publisher
        ros::Publisher movement;
        //Controller
        const ControllerIFace<MoveMsg> * controller;

      public:
        Robot(ros::NodeHandle& nh, std::string name, std::string movementTopic, const ControllerIFace<MoveMsg> * controller) {
          this->name = name;
          this->controller = controller;
          // segundo parametro: si acumulamos varios mensajes, solo el último será enviado.
          movement = nh.advertise<MoveMsg>(topic_name(name, movementTopic), 1);
        }

        void doCycle(void) const { movement.publish(controller->decision(this)); }

  };
}
