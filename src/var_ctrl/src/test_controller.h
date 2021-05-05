#pragma once
#include "controller.h"

#include "turtlebot.h"

#include "types.h"

namespace VAR_CTRL {

  class TestController : public Controller<TwistMove, Turtlebot> {
    protected:
      TwistMove doTypedDecision(const Turtlebot * robot) const;

  };

}

