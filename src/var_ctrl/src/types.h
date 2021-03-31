#pragma once

#include "pcl/point_types.h"
#include "pcl_ros/point_cloud.h"

namespace VAR_CTRL{
  enum Cam {front, back1, back2, CAM_NUM};

  typedef pcl::PointXYZ Point3D;
  typedef pcl::PointCloud<Point3D> PointCloud3D;

}
