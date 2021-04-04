#include "controller.h"
#include "info.h"
#include "types.h"

namespace VAR_CTRL {

  class TestController : public Controller {
    protected:
      Info<PointCloud3D, TurtlebotCams> source;

     void decision(void);

    public:
      TestController(ros::NodeHandle& nh, std::string robot_name, std::string sensors[]);

  };

}