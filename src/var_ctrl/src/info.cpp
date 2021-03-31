#include "info.h"

#include <iostream>

/*  usages
    const pcl::PointXYZ &pt = filtered.points[0];
    std::cout << "\t(" << pt.x << ", " << pt.y << ", " << pt.z << ")" << std::endl;
*/

namespace VAR_CTRL {
  Info::Info(ros::NodeHandle& nh, std::string robot_name, std::string sensors[]) {

    std::string data = "/depth/points";
    
    cams[front] = nh.subscribe("/"+robot_name+"/"+sensors[front]+data, 1, &Info::callback<front>, this);
    cams[back1] = nh.subscribe("/"+robot_name+"/"+sensors[back1]+data, 1, &Info::callback<back1>, this);
    cams[back2] = nh.subscribe("/"+robot_name+"/"+sensors[back2]+data, 1, &Info::callback<back2>, this);
  }


  Point3D Info::get_data(Cam cam, unsigned pos) {return data[pos];}
  unsigned Info::get_size(Cam cam) {return data.size();}

  void Info::callback(const PointCloud3D::ConstPtr& msg, Cam cam) {
    std::cout << "CALLBACK from " << cam << " CAM_NUM " << CAM_NUM << std::endl;
    std::cout << "\twidth " << msg->width << " height " << msg->height << " points: " << msg->points.size() << std::endl;
    PointCloud3D d;
    std::vector<int> i;
    std::vector<Point3D> data;
    pcl::removeNaNFromPointCloud(*msg, d, i);
    for(int i=0; i<d.size(); ++i) {
      data.push_back(d[i]);
    }
  }
}
