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
        self.publisher = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.create_subscription(Pose,'/turtle1/pose',self.turtle_pos,10)
        self.timer = self.create_timer(0.1, self.timer_callback)
        self.velocity = Twist()
        self.exit_flag = False
        self.spawn_pizza_client = self.create_client(GivePosition,'/spawn_pizza')
        self.turtle_position = [0,0]
        self.keep_pose = []

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
            self.keep_pose = []
        elif key == 'c':
            # eat all of the keep pose -> send keep pose to teleop controller 
            pass
        elif key == 'e':
            self.velocity.linear.x = 0.0
            self.velocity.angular.z = 0.0


        # Publish the velocity
        self.publisher.publish(self.velocity)

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
