#include "controller.h"
#include "info.h"
#include "types.h"

#include "pcl/filters/filter.h"

namespace VAR_CTRL {

  class WanderController : public Controller {
    protected:
      Info<PointCloud3D, TurtlebotCams> source;

      ros::Publisher datos;

      void decision(void);

      bool is_relevant(Point3D p);

    public:
      WanderController(ros::NodeHandle& nh, std::string robot_name, std::string sensors[]);

  };

}
