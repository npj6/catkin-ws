#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "ros/ros.h"
#include "sensor_msgs/PointCloud2.h"
#include "sensor_msgs/PointField.h"
#include "pcl/point_types.h"
#include "pcl_ros/point_cloud.h"
#include "pcl/filters/filter.h"


#include "types.h"


namespace VAR_CTRL {
  typedef pcl::PointXYZ Point3D;
  typedef pcl::PointCloud<Point3D> PointCloud3D;

  class Info{
    protected:
      ros::Subscriber cams[CAM_NUM];
      std::vector<Point3D> data;

    public:
      Point3D get_data(Cam cam, unsigned pos);
      unsigned get_size(Cam cam);

      Info(ros::NodeHandle& nh, std::string robot_name, std::string sensors[]);

      template<Cam camera>
      void callback(const PointCloud3D::ConstPtr& msg) {
        callback(msg, camera);
      }

      void callback(const PointCloud3D::ConstPtr& msg, Cam camera);
  };
}
