#pragma once
#include "controller.h"

#include "turtlebot.h"

#include "types.h"

#include <iostream>
#include <cstdlib>

namespace VAR_CTRL {

  class MapController : public Controller<TwistMove, Turtlebot> {
    protected:
      TwistMove doTypedDecision(const Turtlebot * robot) const;

  };

}

