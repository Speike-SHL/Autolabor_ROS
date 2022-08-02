#!/usr/bin/env python3
# -*- encoding: utf-8 -*-
'''
@File    :   helloworld_p.py
@Time    :   2022/08/03 00:29:03
@Author  :   Speike 
@Contact :   shao-haoluo@foxmail.com
@Desc    :   None
'''

import rospy

if __name__ == "__main__":
    rospy.init_node("hello")
    rospy.loginfo("Hello world,I am python")
