#!/usr/bin/python3

from turtle_bringup.dummy_module import dummy_function, dummy_var
import rclpy
from rclpy.node import Node

from std_msgs.msg import String 

from geometry_msgs.msg import Twist,Point,TransformStamped,PoseStamped

from turtlesim.msg import Pose

import numpy as np

from turtlesim_plus_interfaces.srv import GivePosition

from std_srvs.srv import Empty 

# from nav_msgs.msg import Odometry

# from tf2_ros import  TransformBroadcaster

from tf_transformations import quaternion_from_euler

import math

from controller_interfaces.srv import SetTarget,SetParam

from sun_interfaces.srv import PizzaPose

class teleop_controller(Node):
    def __init__(self):
        super().__init__('teleop_controller')

        self.declare_parameter('kp',4.0)


        self.kp = self.get_parameter('kp').get_parameter_value().double_value

        self.declare_parameter('ki',5.0)


        self.kp_a = self.get_parameter('ki').get_parameter_value().double_value
        
        self.cmd_vel_pub = self.create_publisher(Twist,'cmd_vel',10) 
        self.create_subscription(Pose,'pose',self.pose_callback,10)


        self.create_timer(0.1,self.timmer_callback)

        self.spawn_pizza_client = self.create_client(GivePosition,'/spawn_pizza')

        self.eat_pizza_client = self.create_client(Empty, 'eat')

        self.srv_controll_parameter = self.create_service(SetParam,'Set_Param',self.set_Param)

        

    def spawn_pizza(self, x ,y):
        position_request = GivePosition.Request()
        position_request.x = x
        position_request.y = y
        self.spawn_pizza_client.call_async(position_request)

    def cmdvel(self, v ,w):
        msg = Twist()
        msg.linear.x = v
        msg.angular.z = w
        self.cmd_vel_pub.publish(msg)

    def eat_pizza(self):
        eat_request = Empty.Request()
        self.eat_pizza_client.call_async(eat_request) 

    def timmer_callback(self):
        if self.e_count < self.m_count :
            if self.eat_state == 0:
                self.last_pose = self.goal_pose[0]
                self.eat_state = 1
                print("call back")
                print(self.goal_pose)
                self.condition_count += 1
                print("eat count = ",self.e_count,"eat state = ",self.eat_state)

            d_x = self.last_pose[0] - self.R_pose[0] 
            d_y = self.last_pose[1] - self.R_pose[1]
            d = math.sqrt((d_x*d_x)+(d_y*d_y))
            turtle_angle = math.atan2(d_y,d_x)
            angular_error = turtle_angle - self.R_pose[2]
            e = math.atan2(math.sin(angular_error),math.cos(angular_error))
            vx = self.kp * d
            w = self.kp_a * e

            if d <= 0.2 and angular_error < 1.0 :
                self.eat_pizza()
                self.eat_state = 0
                self.e_count += 1
                vx = 0.0
                w = 0.0
                self.goal_pose.pop(0)
                print("Done")
                print(self.goal_pose)
                print("eat count = ",self.e_count,"eat state = ",self.eat_state)
                print(self.condition_count)
                print(" ")
            self.cmdvel(vx,w)

def main(args=None):
    rclpy.init(args=args)
    node = teleop_controller()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__=='__main__':
    main()