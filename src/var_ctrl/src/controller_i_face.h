#pragma once

#include "robot.h"

namespace VAR_CTRL {
  //forward declaration of robot
  template<class T>
    class Robot;

  template<class MoveMsg>
    class ControllerIFace {
      protected:
        virtual MoveMsg doDecision(const Robot<MoveMsg> * robot ) const = 0;

      public:
        MoveMsg decision(const Robot<MoveMsg> * robot) const {
          return doDecision(robot);
        }
    };
}
