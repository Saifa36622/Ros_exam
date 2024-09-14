from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess,DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():

    launch_des = LaunchDescription()

    name = "t_name"

    turtlesim = Node(
    package='turtlesim_plus',
    namespace=name,
    executable='turtlesim_plus_node.py',
    name='turtlesim'
    )

    launch_des.add_action(turtlesim)

    interface_name = 'turtlesim/srv/Kill'
    cmd2 = (
    f"ros2 service call /remove_turtle {interface_name} "
    f'{{name: "/{name}/turtle1"}}'
    )

    kill_turtle = ExecuteProcess(
        cmd=[cmd2],
        shell=True
    )
    launch_des.add_action(kill_turtle)

    

    interface_name = 'turtlesim/srv/Spawn'
    cmd2 = (
    f'ros2 service call /spawn_turtle {interface_name} '
    f'"{{x: {0.0}, y: {0.0}, theta: {0.0}, name: {name}}}"'
    )

    set_turtle = ExecuteProcess(
        cmd=[cmd2],
        shell=True
    )
    launch_des.add_action(set_turtle)

    tele_control_turtlesim = Node(
    package='saifa_pack',
    namespace=name,
    executable='teleop_controller.py',
    name= name + "teleop_controller" 
    )

    launch_des.add_action(tele_control_turtlesim)


    return launch_des
