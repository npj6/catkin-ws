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
  class Info{
    protected:
      ros::Subscriber cams[CAM_NUM];
      PointCloud3D data[CAM_NUM];

    public:
      Point3D get_data(Cam cam, unsigned pos);
      unsigned get_size(Cam cam);

      void initialize(ros::NodeHandle& nh, std::string robot_name, std::string sensors[]);

      template<Cam camera>
      void callback(const PointCloud3D::ConstPtr& msg) {
        callback(msg, camera);
      }

      void callback(const PointCloud3D::ConstPtr& msg, Cam camera);
  };
}
