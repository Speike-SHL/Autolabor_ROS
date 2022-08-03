/***************************************************************
 * @file       topic_publisher_2_1.cpp
 * @path       src/learn_topic/src/topic_publisher_2.1.cpp
 * @author     Speike
 * @email      shao-haoluo@foxmail.com
 * @date       2022/08/04 01:01:30
 * @brief      话题发布者:循环发布信息"HelloWorld 后缀数字编号"
 **************************************************************/

//* 1.包含头文件
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>

int main(int argc, char *argv[])
{
    // 设置编码
    setlocale(LC_ALL, "");
    //* 2.初始化ROS节点
    // 参数1和参数2 后期为节点传值会使用
    // 参数3 是节点名称，是一个标识符，需要保证运行后，在 ROS 网络拓扑中唯一
    ros::init(argc, argv, "publisher_node");
    //* 3.实例化节点句柄
    ros::NodeHandle nh;
    //* 4.创建发布者
    //泛型: 发布的消息类型
    //参数1: 要发布到的话题
    //参数2: 队列中最大保存的消息数，超出此阀值时，先进的先销毁(时间早的先销毁)
    ros::Publisher pub = nh.advertise<std_msgs::String>("publisher_topic", 10);
    //* 5.设置发布频率,?HZ,与while循环中的rate.sleep配合使用
    ros::Rate rate(1);
    // 先睡眠2秒等待节点向master注册完成再进行发布
    ros::Duration(2.0).sleep();
    //* 6.组织被发布的数据，并编写逻辑发布数据
    // 创建要发布的消息对象
    std_msgs::String msg;
    std::string msg_front = "hello, I am learning topic.";
    int count = 0;
    // 如果ros节点一直存活
    while (ros::ok())
    {
        count++;
        // 将要发布的话和数字拼接
        msg.data = msg_front + std::to_string(count);
        //* 7.发布消息
        pub.publish(msg);
        // c_str为将c++中string类转换为c风格字符串，对应前面%s
        ROS_INFO("发布者发布的消息为:%s", msg.data.c_str());
        // spin一次调用回调函数后可以继续执行，多用于while中，注意与spin的区别
        //[ros::spin与ros::spinOnce](https://blog.csdn.net/weixin_40215443/article/details/103793316?spm=1001.2101.3001.6650.5&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-5-103793316-blog-105555031.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-5-103793316-blog-105555031.pc_relevant_multi_platform_whitelistv3)
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}
