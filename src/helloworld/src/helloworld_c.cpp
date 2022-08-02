#include "ros/ros.h"

int main(int argc, char *argv[])
{
	ros::init(argc, argv, "hello_node");
	ROS_INFO("hello world,I am c++");
	return 0;
}
