#include "xentrinobot_pid/pid_core.h"

int main(int argc, char **argv)
{

  ros::init(argc, argv, "pid_configure");
  ros::NodeHandle nh;

  //LinoPID *lino_pid = new LinoPID();

  dynamic_reconfigure::Server<xentrinobot_pid::PidStateConfig> dr_srv;
  dynamic_reconfigure::Server<xentrinobot_pid::PidStateConfig>::CallbackType cb;
  cb = boost::bind(&configCallback, _1, _2);
  dr_srv.setCallback(cb);

  double p;
  double d;
  double i;
  int rate;

  ros::NodeHandle pnh("~");
  pnh.param("p", p, 0.6);
  pnh.param("d", d, 0.3);
  pnh.param("i", i, 0.5);
  pnh.param("rate", rate, 1);

  //ros::Publisher pub_message = nh.advertise<lino_msgs::PID>("pid", 10);

  ros::Publisher pub_message = nh.advertise<control_msgs::PidState>("pid", 10)
  
  ros::Rate r(rate);

  while (nh.ok())
  {
    publishMessage(&pub_message);
    ros::spinOnce();
    r.sleep();
  }

  return 0;
}
void configCallback(xentrinobot_pid::PidStateConfig &config, double level)
{
  //for PID GUI
  p_ = config.p;
  d_ = config.d;
  i_ = config.i;

}
void publishMessage(ros::Publisher *pub_message)
{
  control_msgs::PidState msg;
  msg.p = p_;
  msg.d = d_;
  msg.i = i_;
  pub_message->publish(msg);
}
