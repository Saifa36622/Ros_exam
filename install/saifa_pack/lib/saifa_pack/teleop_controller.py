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

class teleop_controller(Node):
    def __init__(self):
        super().__init__('teleop_controller')

        self.declare_parameter('kp',6.0)
        self.kp = self.get_parameter('kp').get_parameter_value().double_value

        self.declare_parameter('ki',10.0)
        self.kp_a = self.get_parameter('ki').get_parameter_value().double_value
        
        self.cmd_vel_pub = self.create_publisher(Twist,'cmd_vel',10) 

        self.unsave_p_pose = self.create_service(PizzaPose,"/eatable_pizza",self.unsave_p)

        self.create_timer(0.1,self.timmer_callback)

        # self.spawn_pizza_client = self.create_client(GivePosition,'/spawn_pizza')

        self.eat_pizza_client = self.create_client(Empty, 'eat')

        self.create_subscription(Pose,'pose',self.pose_callback,10)

        self.task_completed_event = threading.Event()

        self.srv_controll_parameter = self.create_service(SetParam,'Set_Param',self.set_Param)
        self.x = []
        self.y = []
        self.all_p = []
        self.goal_pose = []
        self.state = 0
        self.last_pose = [0,0]
        self.R_pose = [0,0,0]
        self.do = 1

        

    # def spawn_pizza(self, x ,y):
    #     position_request = GivePosition.Request()
    #     position_request.x = x
    #     position_request.y = y
    #     self.spawn_pizza_client.call_async(position_request)

    def set_Param(self,request:SetParam.Request ,response:SetParam.Response):
        self.kp = request.kp_linear.data
        self.kp_a = request._kp_angular.data

        return response
    

    def pose_callback(self,msg):
        self.R_pose[0] = msg.x
        self.R_pose[1] = msg.y
        self.R_pose[2] = msg.theta

    def unsave_p(self,request:PizzaPose.Request ,response:PizzaPose.Response):
        self.get_logger().info(f"IN1")
        self.task_completed_event.clear()
        self.get_logger().info(f"IN2")
        self.x = request.x
        self.y = request.y
        for i in range(len(self.x)):
            self.all_p.append([self.x[i],self.y[i]])
        self.get_logger().info(f"IN3")    
        # print(self.all_p)
        self.goal_pose = self.all_p
        self.state = 1
        self.get_logger().info(f"IN4") 

        threading.Thread(target=self.wait_for_task_completion, args=(response,)).start()

        # self.task_completed_event.wait()
        self.get_logger().info(f"IN5") 
        response.isfinish = 1 

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

    def timmer_callback(self):
        if self.state == 0 :
            return

        self.get_logger().info(f"IN6")
        if self.do == 1 :
            self.last_pose = self.goal_pose[0]
            self.do = 0
        elif self.do == 0:
            d_x = self.last_pose[0] - self.R_pose[0] 
            d_y = self.last_pose[1] - self.R_pose[1]
            d = math.sqrt((d_x*d_x)+(d_y*d_y))
            turtle_angle = math.atan2(d_y,d_x)
            angular_error = turtle_angle - self.R_pose[2]
            e = math.atan2(math.sin(angular_error),math.cos(angular_error))
            vx = self.kp * d
            w = self.kp_a * e

            if d <= 0.1 and angular_error < 0.2 :
                self.eat_pizza()
                self.eat_state = 0
                # self.e_count += 1
                vx = 0.0
                w = 0.0
                self.goal_pose.pop(0)
                self.do = 1
                if len(self.goal_pose) == 0 :
                    self.state = 0
                    self.task_completed_event.set()


                
            self.cmdvel(vx,w)

def main(args=None):
    rclpy.init(args=args)
    node = teleop_controller()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__=='__main__':
    main()