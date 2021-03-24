#pragma once

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/PointCloud2.h"
#include "sensor_msgs/PointField.h"
#include <string>

#include <iostream>


namespace VAR_CTRL {
  enum Cam {front, back1, back2, TOTAL_NUM};

  class Controller {
    protected:
      ros::Publisher movement;
      ros::Subscriber depth_pc2[TOTAL_NUM];

      double forward_speed;
      double rotation_speed;

    void move(void);

    template<Cam camera>
    void depth_pc2_callback(const sensor_msgs::PointCloud2::ConstPtr& msg) {
    	depth_pc2_callback(msg, camera);
    }

    void depth_pc2_callback(const sensor_msgs::PointCloud2::ConstPtr& msg, Cam camera);
    public:
      Controller(ros::NodeHandle& nh, std::string robot_name);
      void loop(void);
  };
}
