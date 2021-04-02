#include "test_controller.h"

namespace VAR_CTRL {
  TestController::TestController(ros::NodeHandle& nh, std::string robot_name, std::string sensors[]) :
    Controller(nh, robot_name),
    source(nh, robot_name, sensors, "depth/points")
  { }

  void TestController::decision(void) {
    forward_speed = 1.0;
    rotation_speed = 0.0;

    /*
    #include "pcl/filters/filter.h"
    #include <iostream>

    std::vector<int> i;
    PointCloud3D p;

    pcl::removeNaNFromPointCloud(source.get_data(front), p, i);
    if (0 < p.size())
    std::cout << "x: " << p[0].x << " y: " << p[0].y << " z: " << p[0].z << std::endl;

    pcl::removeNaNFromPointCloud(source.get_data(back1), p, i);
    if (0 < p.size())
    std::cout << "x: " << p[0].x << " y: " << p[0].y << " z: " << p[0].z << std::endl;

    pcl::removeNaNFromPointCloud(source.get_data(back2), p, i);
    if (0 < p.size())
    std::cout << "x: " << p[0].x << " y: " << p[0].y << " z: " << p[0].z << std::endl;
    */
  }
}
