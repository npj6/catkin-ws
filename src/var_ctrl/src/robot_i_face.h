#pragma once

namespace VAR_CTRL {
  class RobotIFace {
    protected:
      virtual void doCycle(void) const = 0;
    public:
      void cycle(void) const { doCycle(); }
  };
}
