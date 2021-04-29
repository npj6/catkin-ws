#pragma once

#include <string>

#include "ros/ros.h"

#include "types.h"

namespace VAR_CTRL {
  template <class DataT>
  class Topic {
    protected:
      ros::Subscriber sub;
      DataT data;

    public:
      const DataT& get_data(void) {return data;}
      void callback(const typename DataT::ConstPtr& msg) {
        data = *msg;
      }
      //OBJECTS CREATED WITH THIS CONSTRUCTOR SHOULD *NOT* BE COPIED
      Topic(ros::NodeHandle& nh, std::string topic) {
        //when the Subscriber gets out of scope, it unsubscribes the topic, avoiding the need of a destructor
        sub = nh.subscribe(topic, 1, &Topic::callback, this);
      }

  };
}
