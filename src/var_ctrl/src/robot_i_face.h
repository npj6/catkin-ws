#pragma once

namespace VAR_CTRL {
  class RobotIFace {
    public:
      virtual void cycle(void) const = 0;
  };
}
