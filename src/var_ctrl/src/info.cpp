#include "info.h"

#include <iostream>

namespace VAR_CTRL {
  void Info::initialize(ros::NodeHandle& nh, std::string robot_name, std::string sensors[]) {

    std::string data = "/depth/points";
    
    cams[front] = nh.subscribe("/"+robot_name+"/"+sensors[front]+data, 1, &Info::callback<front>, this);
    cams[back1] = nh.subscribe("/"+robot_name+"/"+sensors[back1]+data, 1, &Info::callback<back1>, this);
    cams[back2] = nh.subscribe("/"+robot_name+"/"+sensors[back2]+data, 1, &Info::callback<back2>, this);


  }


  Point3D Info::get_data(Cam cam, unsigned pos) {return data[cam][pos];}
  unsigned Info::get_size(Cam cam) {return data[cam].size();}

  void Info::callback(const PointCloud3D::ConstPtr& msg, Cam cam) {
    data[cam] = *msg;
    /*
      std::vector<int> i;
      pcl::removeNaNFromPointCloud(*msg, data[cam], i);
    */
  }
}
