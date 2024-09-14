#!/usr/bin/python3

from turtle_bringup.dummy_module import dummy_function, dummy_var
import rclpy
from rclpy.node import Node
import threading
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

from std_msgs.msg import Int32

class cp_controller(Node):
    def __init__(self):
        super().__init__('cp_controller')
    
        self.declare_parameter('kp',6.0)
        self.kp = self.get_parameter('kp').get_parameter_value().double_value

        self.declare_parameter('ki',10.0)
        self.kp_a = self.get_parameter('ki').get_parameter_value().double_value

        self.declare_parameter('name',"default")
        self.name = self.get_parameter('name').get_parameter_value().string_value

        self.declare_parameter('num',0)
        self.num = self.get_parameter('num').get_parameter_value().integer_value
        
        self.cmd_vel_pub = self.create_publisher(Twist,self.name +"/"+"cmd_vel",10) 

        self.unsave_p_pose = self.create_service(PizzaPose,self.name+"/"+"spawnable_pizza",self.spawnable_pizza)

        self.create_timer(0.1,self.timmer_callback)

        self.spawn_pizza_client = self.create_client(GivePosition,'/spawn_pizza')

        self.create_subscription(Pose,self.name+"/"'pose',self.pose_callback,10)

        self.srv_controll_parameter = self.create_service(SetParam,self.name+"/"'Set_Param',self.set_Param)

        self.check_isfinish = self.create_publisher(Int32,self.name+"/"+'isfinish',10) 

        self.create_subscription(Int32,'/sum_callback',self.sum_callback,10)

        self.x = []
        self.y = []
        self.num = 0
        self.all_p = []
        self.goal_pose = [[0,0]]
        self.state = 0
        self.last_pose = [0]
        self.R_pose = [0,0,0]
        self.do = 0 
        self.count = 0
        self.i = 0
        self.sum = 0
        self.stop = 0

        msg = Int32()
        msg.data = 0
        self.check_isfinish.publish(msg)


    def set_Param(self,request:SetParam.Request ,response:SetParam.Response):
        self.kp = request.kp_linear.data
        self.kp_a = request._kp_angular.data

        return response
    
    def spawn_pizza(self, x ,y):
        position_request = GivePosition.Request()
        position_request.x = x
        position_request.y = y
        self.spawn_pizza_client.call_async(position_request)


    def pose_callback(self,msg):
        self.R_pose[0] = msg.x
        self.R_pose[1] = msg.y
        self.R_pose[2] = msg.theta

    def spawnable_pizza(self,request:PizzaPose.Request ,response:PizzaPose.Response):
        self.x = request.x
        self.y = request.y
        self.num =  request.number

        for i in range(len(self.x)):
            self.all_p.append([self.x[i],self.y[i]])
        self.get_logger().info(f"IN3")    
        # print(self.all_p)
        self.goal_pose = self.all_p
        self.state = 1
        self.get_logger().info(f"IN4") 

        return response
    def wait_for_task_completion(self, response):
        # This will run in a separate thread
        self.task_completed_event.wait()
        response.isfinish = 1
        self.get_logger().info("Task completed, responding to client.")

    def cmdvel(self, v ,w):
        msg = Twist()
        msg.linear.x = v
        msg.angular.z = w
        self.cmd_vel_pub.publish(msg)

    def eat_pizza(self):
        eat_request = Empty.Request()
        self.eat_pizza_client.call_async(eat_request) 

    def sum_callback(self,msg):
        self.sum = msg.data

    def timmer_callback(self):
            if self.state == 1 :
                return
            if self.do == 0 :
                self.last_pose = self.goal_pose[self.i]
                self.do = 1
            d_x = self.last_pose[0] - self.R_pose[0] 
            d_y = self.last_pose[1] - self.R_pose[1]
            d = math.sqrt((d_x*d_x)+(d_y*d_y))
            turtle_angle = math.atan2(d_y,d_x)
            angular_error = turtle_angle - self.R_pose[2]
            e = math.atan2(math.sin(angular_error),math.cos(angular_error))
            vx = self.kp * d
            w = self.kp_a * e

            if d <= 0.1 and angular_error < 0.2 :
                self.spawn_pizza(float(self.last_pose[0]),float(self.last_pose[1]))
                self.eat_state = 0
                self.count += 1
                vx = 0.0
                w = 0.0
                self.do = 0
                self.i += 1
                if self.stop == 1 :
                    self.state = 1
                    return
                if len(self.goal_pose) == self.count :
                    msg = Int32()
                    msg.data = 1
                    self.check_isfinish.publish(msg)
                    while self.sum != 4 :
                         continue
                    self.last_pose = [10,10]
                    self.do = 1
                    self.stop = 1

            self.cmdvel(vx,w)

def main(args=None):
    rclpy.init(args=args)
    node = cp_controller()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__=='__main__':
    main()