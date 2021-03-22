#include "xentrinobot_pid/include/pid_core.h"


void messageCallback(const control_msgs::PidState& msg);

int main(int argc, char **argv)
{

  ros::init(argc, argv, "pid_listener");
  ros::NodeHandle nh;

  int rate;

  ros::NodeHandle pnh("~");
  pnh.param("rate", rate, int(40));


  ros::Subscriber sub_message = nh.subscribe("pid", 1000,messageCallback);

  ros::Rate r(rate);

  // Main loop.
  while (nh.ok())
  {
    ros::spinOnce();
    r.sleep();
  }

  return 0;
} // end main()

void messageCallback(const control_msgs::PidState& msg)
{
  xentrinobotPID.p_ = msg.p_term;
  xentrinobotPID.d_ = msg.d_term;
  xentrinobotPID.i_ = msg.i_term;

  //echo P,I,D
  ROS_INFO("P: %f", xentrinobotPID.p_);
  ROS_INFO("D: %f", xentrinobotPID.d_);
  ROS_INFO("I: %f", xentrinobotPID.i_);
}


