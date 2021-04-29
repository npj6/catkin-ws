#pragma once

#include "move_controller.h"

#include "robot.h"

namespace VAR_CTRL {
  template<class MoveMsg, class RobotT>
    class Controller : public MoveController<MoveMsg> {
      protected:

        MoveMsg doDecision(Robot<MoveMsg> const * robot ) const {
          return doTypedDecision(dynamic_cast<RobotT const *>(robot));
        }

        virtual MoveMsg doTypedDecision(RobotT const * robot) const = 0;
    };
}


