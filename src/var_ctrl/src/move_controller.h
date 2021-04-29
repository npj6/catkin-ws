#pragma once

#include "robot.h"

namespace VAR_CTRL {
        //forward declaration of robot
        template<class T>
          class Robot;

  template<class MoveMsg>
    class MoveController {
      protected:
        virtual MoveMsg doDecision(Robot<MoveMsg> const * robot ) const = 0;

      public:

        MoveMsg decision(Robot<MoveMsg> const * robot) const {
          return doDecision(robot);
        }
    };
}
