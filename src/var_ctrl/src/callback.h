#pragma once

namespace VAR_CTRL {
  template <class CoreT>
  class Callback {
    protected:
      CoreT data;
    public:
      CoreT get_data(void) {return data;}
      void callback(const typename CoreT::ConstPtr& msg) {
        data = *msg;
      }
  };
}
