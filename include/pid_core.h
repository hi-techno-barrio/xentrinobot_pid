#ifndef PID_CORE_H
#define PID_CORE_H

#include "ros/ros.h"
#include "ros/time.h"

// ROS Control msgs.
#include <control_msgs/PidState.h>

// Dynamic reconfigure includes
#include <dynamic_reconfigure/server.h>

// Auto-generated from cfg/ directory.
#include "xentrinobot_pid/PidStateConfig.h"

class xentrinobotPID
{
public:
  //void configCallback(xentrinobot_pid::PidStateConfig &config, double level);
  //void publishMessage(ros::Publisher *pub_message);
  //void messageCallback(const control_msgs::PidState& msg);

  double p_;
  double d_;
  double i_;

};
#endif
