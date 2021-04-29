#pragma once

#include "ros/ros.h"

#include "robot_i_face.h"
#include "move_controller.h"
#include "utils.h"

#include <string>

namespace VAR_CTRL {

  //forward declaration of move_controller
  template<class T>
    class MoveController;

  template <class MoveMsg>
    class Robot : public RobotIFace {
 
      protected:

        //Robot name
        std::string name;
        //Movement publisher
        ros::Publisher movement;
        //Controller
        const MoveController<MoveMsg> * controller;

      public:
        Robot(ros::NodeHandle& nh, std::string name, std::string movementTopic, const MoveController<MoveMsg> * controller) {
          this->name = name;
          this->controller = controller;
          // segundo parametro: si acumulamos varios mensajes, solo el último será enviado.
          movement = nh.advertise<MoveMsg>(topic_name(name, movementTopic), 1);
        }

        void doCycle(void) const { movement.publish(controller->decision(this)); }

  };
}
