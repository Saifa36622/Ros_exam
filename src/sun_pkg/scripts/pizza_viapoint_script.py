#!/usr/bin/python3

import rclpy
from rclpy.node import Node
import yaml
import os

# Additional interfaces
from sun_interfaces.srv import PizzaPose
from turtlesim_plus_interfaces.srv import GivePosition
from rcl_interfaces.msg import SetParametersResult
from std_srvs.srv import Trigger

class PizzaViapointNode(Node):
    def __init__(self):
        super().__init__('pizza_viapoint_node')
        
        # Declare parameters
        self.declare_parameter('max_pizza', 20)
        self.declare_parameter('name', 't_name')
        
        self.max_pizza = self.get_parameter('max_pizza').get_parameter_value().integer_value
        
        # Create the service server
        self.clear_pizza_server = self.create_service(Trigger, 'clear_pizza', self.clear_pizza_callback)
        self.ready_to_spawn_pizza = self.create_service(GivePosition, 'ready_to_spawn_pizza', self.spawn_pizza_request)
        self.save_pizza_server = self.create_service(Trigger, 'save_pizza', self.save_pizza_callback)
        self.get_logger().info('Service server ready to receive pizza position.')

        # Create the service client
        self.clear_pizza_to_controller = self.create_client(PizzaPose, 'eatable_pizza')
        self.spawn_pizza_client = self.create_client(GivePosition, 'spawn_pizza')
        
        # Set path of .yaml file
        self.yaml_file_path = os.path.join(os.path.dirname(__file__), '../pizza_pose/pizza_pose.yaml')

        # Check if the directory exists, create it if necessary
        directory = os.path.dirname(self.yaml_file_path)
        if not os.path.exists(directory):
            os.makedirs(directory)
            self.get_logger().info(f"Directory created: {directory}")
            
        # Additional variables
        self.count_pizza = 0
        self.keep_pose = []
        self.update_number = 0
        
        # Add a callback to dynamically update parameters
        self.add_on_set_parameters_callback(self.on_parameter_update)
    
    def clear_pizza_callback(self, request, response):
        
        temp_x = []
        temp_y = []
        
        for i in range (len(self.keep_pose)):
            temp_x.append(self.keep_pose[i][0])
            temp_y.append(self.keep_pose[i][1])
            
        clear_to_controller = PizzaPose.Request()
        clear_to_controller.x = temp_x
        clear_to_controller.y = temp_y
        clear_to_controller.number = 0
        
        self.clear_pizza_to_controller.call_async(clear_to_controller)
        self.get_logger().info("Start clear pizza")
        self.keep_pose = []
        self.count_pizza = 0
        
        return response
    
    def spawn_pizza_request(self, request, response):
        
        if self.count_pizza < self.max_pizza:
            self.count_pizza += 1
            position_request = GivePosition.Request()
            position_request.x = request.x
            position_request.y = request.y
            self.keep_pose.append([position_request.x, position_request.y])
            self.spawn_pizza_client.call_async(position_request)
            self.get_logger().info(f'Pizza spawn: {self.count_pizza} pcs')
            return response
        else :
            self.get_logger().warning(f'Just spawn pizza only {self.max_pizza} mother fucker')
            return response
        
    
    def save_pizza_callback(self, request, response):
        
        if self.update_number < 4:
            self.update_number += 1
            self.get_logger().info(f"Update pizza position {self.update_number}")
            
            # Handle the incoming 1D array of float64
            self.get_logger().info(f"Received pizza pose to save to pizza_pose.yaml")
            
            print(self.keep_pose, self.update_number)
            
            # Call the function to append data to YAML
            self.append_to_yaml(self.keep_pose, self.update_number)
            
            # Save data to .yaml
            self.get_logger().info(f"Completed to save data to .yaml file")
            
            self.count_pizza = 0
            self.keep_pose = []
            
            return response
        else:
            self.get_logger().warning(f"Can't update pizza position after {self.update_number} times")  
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

    def on_parameter_update(self, params):
        # Callback to handle parameter updates
        for param in params:
            if param.name == 'max_pizza':
                self.max_pizza = param.value
                self.get_logger().info(f'Update max pizza changed to: {self.max_pizza} pcs')

        return SetParametersResult(successful=True)
    
def main(args=None):
    rclpy.init(args=args)
    node = PizzaViapointNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__=='__main__':
    main()
