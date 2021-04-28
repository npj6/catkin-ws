#pragma once

#include <string>

#include "ros/ros.h"

#include "types.h"
#include "callback.h"

namespace VAR_CTRL {
  template<class InfoT, typename SensorT>
  class Info{
    protected:
      ros::Subscriber sensors[SensorT::NUM];
      Callback<InfoT> data[SensorT::NUM];

    public:
      InfoT get_data(SensorT s) {return data[s].get_data();}

      //OBJECTS CREATED WITH THIS CONSTRUCTOR SHOULD *NOT* BE COPIED
      Info(ros::NodeHandle& nh, std::string robot_name, std::string sensor_names[], std::string topic)  {
        //when the Subscriber gets out of scope, it unsubscribes the topic, avoiding the need of a destructor
        for(std::size_t s=0; s < SensorT::NUM; ++s) {
          sensors[s] = nh.subscribe(robot_name+"/"+sensor_names[s]+"/"+topic, 1, &Callback<InfoT>::callback, &data[s]);
        }
      }
  };
}
