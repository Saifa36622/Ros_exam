#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import sys
import select
import termios
import tty
from turtlesim_plus_interfaces.srv import GivePosition
from turtlesim.msg import Pose
from sun_interfaces.srv import PizzaPose

# getKey function (based on teleop_twist_keyboard)
def getKey():
    tty.setraw(sys.stdin.fileno())
    select.select([sys.stdin], [], [], 0)
    key = sys.stdin.read(1)
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key

class TeleopTurtle(Node):
    def __init__(self):
        super().__init__('teleop_turtle')
        self.declare_parameter("name","t_name")
        self.name = self.get_parameter('name').get_parameter_value().string_value
        # ros2 run saifa_pack teleop_turtle.py --ros-args -p name:="t_name"
        self.publisher = self.create_publisher(Twist, '/' +self.name +'/cmd_vel', 10)
        self.create_subscription(Pose,'/' +self.name + '/pose',self.turtle_pos,10)
        
        self.pizza_pose_client = self.create_client(PizzaPose, 'save_pizza')
        
        # Wait for the service to be available
        while not self.pizza_pose_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for the server to be available...')
            
        self.get_logger().info('Conected to server')
        
        self.timer = self.create_timer(0.1, self.timer_callback)
        self.velocity = Twist()
        self.exit_flag = False
        self.spawn_pizza_client = self.create_client(GivePosition,'/spawn_pizza')
        self.turtle_position = [0,0]
        self.keep_pose = []
        self.save_times = 0

    def turtle_pos(self,msg):
        self.turtle_position[0] = msg.x
        self.turtle_position[1] = msg.y

    def timer_callback(self):
        key = getKey()
        if key == 'w':
            self.velocity.linear.x = 2.0
            self.velocity.angular.z = 0.0
        elif key == 's':
            self.velocity.linear.x = -2.0
            self.velocity.angular.z = 0.0
        elif key == 'a':
            self.velocity.linear.x = 0.0
            self.velocity.angular.z = 2.0
        elif key == 'd':
            self.velocity.linear.x = 0.0
            self.velocity.angular.z = -2.0
        elif key == 'q':
            self.exit_flag = True
            return
        elif key == 'r':
            position_request = GivePosition.Request()
            position_request.x = self.turtle_position[0]
            position_request.y = self.turtle_position[1]
            self.keep_pose.append(self.turtle_position)
            print(self.keep_pose)
            self.spawn_pizza_client.call_async(position_request)
        elif key == 'u':
            # write to yaml
            temp_x = []
            temp_y = []
            self.save_times += 1
            for i in range (len(self.keep_pose)):
                temp_x.append(self.keep_pose[i][0])
                temp_y.append(self.keep_pose[i][1])
            self.save_pizza_request(temp_x, temp_y, self.save_times)
            self.keep_pose = []
            self.get_logger().info(f"Update pizza postion {self.save_times}")

        elif key == 'c':
            # eat all of the keep pose -> send keep pose to teleop controller 
            # self.
            pass
            
        elif key == 'e':
            self.velocity.linear.x = 0.0
            self.velocity.angular.z = 0.0


        # Publish the velocity
        self.publisher.publish(self.velocity)
    
    def save_pizza_request(self, x, y, save_times):
        # Prepare the request message
        request = PizzaPose.Request()
        request.x = x
        request.y = y
        request.number = save_times
        
        # Call the service and wait for a response
        self.pizza_pose_client.call_async(request)

def main(args=None):
    global settings
    settings = termios.tcgetattr(sys.stdin)

    rclpy.init(args=args)
    teleop_turtle = TeleopTurtle()

    try:
        while rclpy.ok() and not teleop_turtle.exit_flag:
            rclpy.spin_once(teleop_turtle)
    except KeyboardInterrupt:
        pass
    finally:
        teleop_turtle.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
