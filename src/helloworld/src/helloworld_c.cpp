/***************************************************************
 * @file       helloworld_c.cpp
 * @path       src/helloworld/src/helloworld_c.cpp
 * @author     Speike
 * @email      shao-haoluo@foxmail.com
 * @date       2022/08/04 01:09:38
 * @brief
 **************************************************************/
#include "ros/ros.h"

int main(int argc, char *argv[])
{
	//解决终端输出ROS_INFO出现乱码
	setlocale(LC_ALL, "");
	ros::init(argc, argv, "hello_node");
	ROS_INFO("hello world,I am c++");
	return 0;
}