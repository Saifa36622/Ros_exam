#!/usr/bin/python3

import rclpy
from rclpy.node import Node
import yaml
import os

# Additional interfaces
from std_srvs.srv import Trigger
from sun_interfaces.srv import PizzaPose

class StartCopyNode(Node):
    def __init__(self):
        super().__init__('start_copy_node')
        
        # Create the service server
        self.read_pizza_pose_server = self.create_service(Trigger, 'read_pizza_pose', self.read_pizza_pose_callback)
        
        # Create the service client
        self.spawnable_pizza_client = self.create_client(PizzaPose, 'spawnable_pizza')
        
        # Define the YAML file path where the 3D array was written
        self.yaml_file_path = os.path.expanduser('~/ros2_yaml_files/pizza_pose.yaml')

    
    def read_pizza_pose_callback(self, request, response):
        
        temp_x = []
        temp_y = []
        temp_n = 0
        request = PizzaPose.Request()
        
        # Read the 3D array from the YAML file
        spawnable_pose = self.read_yaml(self.yaml_file_path)
        
        for plane in spawnable_pose:
                for row in plane:
                    if len(row) == 2:
                        temp_x.append(row[0])
                        temp_y.append(row[1])
                    else:
                        temp_n = row[0]
                        request.x = temp_x
                        request.y = temp_y
                        request.number = temp_n
                        future = self.spawnable_pizza_client.call_async(request)
                        rclpy.spin_until_future_complete(self, future)
                        if future.result() is not None:
                            temp_x = []
                            temp_y = []
                            temp_n = 0
                        else:
                            self.get_logger().error('Service call failed')
                    
        return response
    
    def read_yaml(self, yaml_file_path):
        """Reads the 3D array from a YAML file."""
        try:
            with open(yaml_file_path, 'r') as yaml_file:
                yaml_data = yaml.safe_load(yaml_file)

            # Extract the 3D array from YAML data
            my_3d_array = yaml_data['pizza_pose']

            # Log the 3D array
            self.get_logger().info("3D Array from YAML:")
            for i, plane in enumerate(my_3d_array):
                self.get_logger().info(f"Plane {i + 1}:")
                for row in plane:
                    self.get_logger().info(str(row))

            return my_3d_array
        except FileNotFoundError:
            self.get_logger().error(f"YAML file not found at {yaml_file_path}!")
        except KeyError:
            self.get_logger().error("Key 'my_3d_array' not found in the YAML file!")
        except Exception as e:
            self.get_logger().error(f"An error occurred: {str(e)}")

            
def main(args=None):
    rclpy.init(args=args)
    node = StartCopyNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__=='__main__':
    main()
