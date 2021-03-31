#pragma once

#include <string>
#include <vector>

#include "ros/ros.h"

#include "types.h"

namespace VAR_CTRL {
  template<class InfoT>
  class Info{
    protected:
      ros::Subscriber cams[CAM_NUM];
      PointCloud3D data[CAM_NUM];

    public:
      InfoT get_data(Cam cam) {return data[cam];}

      Info(ros::NodeHandle& nh, std::string robot_name, std::string sensors[], std::string data)  {
        //when the Subscriber gets out of scope, it unsubscribes the topic, avoiding the need of a destructor
        cams[front] = nh.subscribe("/"+robot_name+"/"+sensors[front]+"/"+data, 1, &Info::callback<front>, this);
        cams[back1] = nh.subscribe("/"+robot_name+"/"+sensors[back1]+"/"+data, 1, &Info::callback<back1>, this);
        cams[back2] = nh.subscribe("/"+robot_name+"/"+sensors[back2]+"/"+data, 1, &Info::callback<back2>, this);
      }

      template<Cam camera>
      void callback(const typename InfoT::ConstPtr& msg) {
        callback(msg, camera);
      }

      void callback(const typename InfoT::ConstPtr& msg, Cam cam) {
        data[cam] = *msg;
        /*
         std::vector<int> i;
         pcl::removeNaNFromPointCloud(*msg, data[cam], i);
        */
      }
  };
}
