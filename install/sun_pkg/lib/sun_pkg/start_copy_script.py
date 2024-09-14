#!/usr/bin/python3

import rclpy
from rclpy.node import Node


class StartCopyNode(Node):
    def __init__(self):
        super().__init__('start_copy_node')

def main(args=None):
    rclpy.init(args=args)
    node = StartCopyNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__=='__main__':
    main()
