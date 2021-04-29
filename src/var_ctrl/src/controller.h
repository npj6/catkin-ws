#pragma once

#include "controller_i_face.h"

#include "robot.h"

namespace VAR_CTRL {
  template<class MoveMsg, class RobotT>
    class Controller : public ControllerIFace<MoveMsg> {
      protected:

        MoveMsg doDecision(Robot<MoveMsg> const * robot ) const {
          return doTypedDecision(dynamic_cast<RobotT const *>(robot));
        }

        virtual MoveMsg doTypedDecision(RobotT const * robot) const = 0;
    };
}


