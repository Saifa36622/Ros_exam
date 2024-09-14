#!/usr/bin/python3

import rclpy
from rclpy.node import Node
import yaml
import os

# Additional interfaces
from sun_interfaces.srv import PizzaPose

class PizzaViapointNode(Node):
    def __init__(self):
        super().__init__('pizza_viapoint_node')
        
        # Create the service server
        self.save_pizza_server = self.create_service(PizzaPose, 'save_pizza', self.save_pizza_callback)
        self.get_logger().info('Service server ready to receive 1D array of float64.')

        # Set path of .yaml file
        self.yaml_file_path = os.path.join(os.path.dirname(__file__), '../pizza_pose/pizza_pose.yaml')

        # Check if the directory exists, create it if necessary
        directory = os.path.dirname(self.yaml_file_path)
        if not os.path.exists(directory):
            os.makedirs(directory)
            self.get_logger().info(f"Directory created: {directory}")
    
    def save_pizza_callback(self, request, response):
        temp = []
        # Handle the incoming 1D array of float64
        self.get_logger().info(f"Received pizza pose to save to pizza_pose.yaml")
        
        for i in range(len(request.x)):
            temp.append([request.x[i],request.y[i]])
        
        print(temp, request.number)
        
        # Call the function to append data to YAML
        self.append_to_yaml(temp, request.number)
        
        # Save data to .yaml
        self.get_logger().info(f"Completed to save data to .yaml file")
        
        return response
    
    def clear_yaml(self, file_path):
        self.write_yaml(file_path, {})  # Clears the YAML file by overwriting with an empty dictionary
        self.get_logger().info(f"All data successfully cleared in {file_path}")
        
    def append_to_yaml(self, data, number):
        # Check if the file already exists, and load its content if it does
        if os.path.exists(self.yaml_file_path):
            with open(self.yaml_file_path, 'r') as yaml_file:
                existing_data = yaml.safe_load(yaml_file) or {}  # Read existing YAML data
        else:
            existing_data = {}  # Start with an empty dictionary if the file doesn't exist

        # Append the new data and sending count
        if 'entries' not in existing_data:
            existing_data['entries'] = []
        
        # Add the new data to the entries
        new_entry = {'data': data, 'number': number}
        existing_data['entries'].append(new_entry)

        # Write the updated data back to the YAML file
        with open(self.yaml_file_path, 'w') as yaml_file:
            yaml.dump(existing_data, yaml_file, default_flow_style=False)

        self.get_logger().info(f"Data and count {number} successfully appended to {self.yaml_file_path}")

    def write_yaml(self, file_path, data):
        """Write data to YAML file."""
        try:
            with open(file_path, 'w') as yaml_file:
                yaml.dump(data, yaml_file, default_flow_style=False)
        except Exception as e:
            self.get_logger().error(f"Failed to write to {file_path}: {str(e)}")

def main(args=None):
    rclpy.init(args=args)
    node = PizzaViapointNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__=='__main__':
    main()
