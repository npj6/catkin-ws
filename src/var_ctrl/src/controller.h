#pragma once

#include "controller_i_face.h"

#include "robot.h"

namespace VAR_CTRL {
  template<class MoveMsg, class RobotT>
    class Controller : public ControllerIFace<MoveMsg> {
      protected:

        MoveMsg doDecision(const Robot<MoveMsg> * robot ) const {
          return doTypedDecision(dynamic_cast<const RobotT *>(robot));
        }

        virtual MoveMsg doTypedDecision(const RobotT * robot) const = 0;
    };
}


