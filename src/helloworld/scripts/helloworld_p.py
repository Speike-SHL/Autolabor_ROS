#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   helloworld_p.py"
@Time    :   2022/08/02 15:21:20"
@Author  :   Speike 
@Contact :   shao-haoluo@foxmail.com
@Desc    :   None
'''

import rospy

if __name__ == "__main__":
    rospy.init_node("hello")
    rospy.loginfo("Hello world,I am python")
