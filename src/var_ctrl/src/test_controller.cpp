#include "test_controller.h"

namespace VAR_CTRL {
  geometry_msgs::Twist TestController::doTypedDecision(Turtlebot const * robot) const {
    geometry_msgs::Twist msg;
    msg.linear.x = 1.0;
    msg.angular.z = 0.0;
    return msg;
  }
}


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
