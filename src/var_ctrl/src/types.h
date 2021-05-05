#pragma once

#include "pcl/point_types.h"
#include "pcl_ros/point_cloud.h"
#include "geometry_msgs/Twist.h"

namespace VAR_CTRL{

  typedef pcl::PointXYZ Point3D;
  typedef pcl::PointCloud<Point3D> PointCloud3D;
  typedef geometry_msgs::Twist TwistMove;

}
