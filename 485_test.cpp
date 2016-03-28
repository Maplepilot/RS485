
#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>
#include <iostream>
#include <tf/transform_broadcaster.h>


double count1 = 0.0;
double count2 = 0.0;
double count3 = 0.0;
double count4 = 0.0;
double count5 = 0.0;
double count6 = 0.0;
double count7 = 0.0;
double count8 = 0.0;

ros::Publisher chatter_pub1;
ros::Publisher chatter_pub2;
ros::Publisher chatter_pub3;
ros::Publisher chatter_pub4;
ros::Publisher chatter_pub5;
ros::Publisher chatter_pub6;
ros::Publisher chatter_pub7;
ros::Publisher chatter_pub8;

int main(int argc, char **argv)
{

  ros::init(argc, argv, "serial_test");

  ros::NodeHandle n;

  chatter_pub1 = n.advertise<geometry_msgs::Vector3>("cmd1", 1000);
  chatter_pub2 = n.advertise<geometry_msgs::Vector3>("cmd2", 1000);
  chatter_pub3 = n.advertise<geometry_msgs::Vector3>("cmd3", 1000);
  chatter_pub4 = n.advertise<geometry_msgs::Vector3>("cmd4", 1000);
  chatter_pub5 = n.advertise<geometry_msgs::Vector3>("cmd5", 1000);
  chatter_pub6 = n.advertise<geometry_msgs::Vector3>("cmd6", 1000);
  chatter_pub7 = n.advertise<geometry_msgs::Vector3>("cmd7", 1000);
  chatter_pub8 = n.advertise<geometry_msgs::Vector3>("cmd8", 1000);

  ros::Rate loop_rate(10);

  while (ros::ok())
  {
	if (count1<=10)
		{
		    geometry_msgs::Vector3 vector3;
		    vector3.x=count1;
		    chatter_pub1.publish(vector3);
		    vector3.x=count2;
		    chatter_pub2.publish(vector3);
		    vector3.x=count3;
		    chatter_pub3.publish(vector3);
		    vector3.x=count4;
		    chatter_pub4.publish(vector3);
		    vector3.x=count5;
		    chatter_pub5.publish(vector3);
		    vector3.x=count6;
		    chatter_pub6.publish(vector3);
		    vector3.x=count7;
		    chatter_pub7.publish(vector3);
		    vector3.x=count8;
		    chatter_pub8.publish(vector3);
		    ros::spinOnce();
		    loop_rate.sleep();
		    count1=count1+0.001;
		    count2=count2+0.001;
		    count3=count3+0.001;
		    count4=count4+0.001;
		    count5=count5+0.001;
		    count6=count6+0.001;
		    count7=count7+0.001;
		    count8=count8+0.001;
		}
  }


  return 0;
}
