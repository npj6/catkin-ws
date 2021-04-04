#include "wander_controller.h"

#include <iostream>
#include <algorithm>

namespace VAR_CTRL {
  WanderController::WanderController(ros::NodeHandle& nh, std::string robot_name, std::string sensors[]) :
    Controller(nh, robot_name),
    source(nh, robot_name, sensors, "depth/points")
  {
    datos = nh.advertise<PointCloud3D>("/"+robot_name+"/DATOS", 1);
  }

  void WanderController::decision(void) {
    forward_speed = 0.0;
    rotation_speed = 0.0;


    std::vector<int> indexes;
    PointCloud3D pointcloud;

    pcl::removeNaNFromPointCloud(source.get_data(front), pointcloud, indexes);

    std::cout << "WANDER" << std::endl;

    //points that are in the way of the bot
    PointCloud3D relevant_points;
    if(0 < pointcloud.size())
      relevant_points.push_back(pointcloud[0]);
    for(int i=1; i<pointcloud.size(); ++i) {
      Point3D &cp = pointcloud[i];
      //downsample
      float distance = -1.0;
      for(int j=0; j<relevant_points.size(); ++j) {
        Point3D &lp = relevant_points[j];
        float new_distance = (lp.x-cp.x)*(lp.x-cp.x) + (lp.z-cp.z)*(lp.z-cp.z) + (lp.y-cp.y)*(lp.y-cp.y);
        if(distance == -1.0 || new_distance < distance) {
          distance = new_distance;
        }
      }
      //down samples and avoids positive y to avoid floor
      if(0.0025 < distance && cp.y < 0) {
        relevant_points.push_back(cp);
        if(!(true))
          pointcloud[i] = Point3D(NAN, NAN, NAN);
      } else {
        pointcloud[i] = Point3D(NAN, NAN, NAN);
      }
    }
    std::sort(
      relevant_points.begin(),
      relevant_points.end(),
      [](const Point3D & a, const Point3D & b) -> bool {return a.x < b.x;});
    for(int i=0; i<relevant_points.size(); ++i) {
      Point3D &cp = relevant_points[i];
      std::cout << "\tx: " << cp.x
        << " y: " << cp.y
        << " z: " << cp.z
        << std::endl;
    }
    std::cout << "og not nan size: " << pointcloud.size() << " new size: " << relevant_points.size() << std::endl;
    datos.publish(pointcloud);//relevant_points);
  }

  bool WanderController::is_relevant(Point3D p) {
    float radius = 0.2;
    float min_height = 0.01; //you dont collide with floor
    return min_height < p.z;
  }
}
