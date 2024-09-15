# FRA501 Amazing turtle

In this project we will develop a little fun turtle project using simple libraly on ubuntu  So Ubuntu (22.04 LTS is recommend) with Ros humble 

* [Ubuntu](https://releases.ubuntu.com/jammy/)
* [ROS_Humble](https://docs.ros.org/en/humble/Installation.html)

## Basic knowlegde and How to use 
first you need to clone your ptoject to your computer using command 

```
git clone https://github.com/Saifa36622/Ros_exam.git
```
paste this in the terminal or powershell of your prefer and then use this command to navigate to the working directory

```
cd Ros_exam
```
if this is the first time you using ROS you need to 
```
source /opt/ros/humble/setup.bash
```
to source setup-file from ros 

then `colcon build` to build up the project 

```
colcon build
```
if you dont have the colcon yet you can watch how to install and use it at [ros humble tutorials](https://docs.ros.org/en/humble/Installation.html)

<br>

and for the most of the project the commadline that we going to use is 
```
ros2 launch saifa_pack turtle_1.launch.py
```
to open the most of the project file and 
```
ros2 run saifa_pack teleop_turtle.py
```
to open tele-operation file to control the turtle in this project 

<br>

then you might have too install some additional libraly for this project 
* for read/edit/etc .yaml file you need to install pyyaml
```
pip install pyyaml
```

# System Architect

![image](https://github.com/user-attachments/assets/710f584a-7f18-49fc-8189-dd216e7c09ee)

- **Tele-op Architect**

<img src="https://github.com/user-attachments/assets/40e46043-d574-466f-8cc4-b8a72b2b6877" alt="alt text" width="500" height="500">

![image](https://github.com/user-attachments/assets/9b6d481a-03e4-4ed1-af22-388dda36b0be)

Tha main point of this node is to be manual controller for users by input via keyboard and control the velocity and the acceleration of the 
turtle from point to point .There is going to be 2 node for this operation that are <br>
- teleop_turtle -> this node is use to recieve input from the user keyboard and move turtle in the ways user inteded
- teleop_controller -> this node is use in special occasion that is when user press clear ,we are going to ignore the input from the keyboard and use position and way point from our code calculation
  to eat all remain of the pizza
<br>
and from the upper imagge it going to indicate that these node going  to be the one that recieve input from the user ,So we internde that we are going to save the input from user to .yaml file via these node


# Fuction available
* Teleoperation
  So how to use it you need to run this command first
  ```
  ros2 launch saifa_pack turtle_1.launch.py
  ```
  to open the turtle bot in the terminal like this

![image](https://github.com/user-attachments/assets/e99c7a4f-2d3a-4205-af78-d8b9226d213c)

there is going to be 2 terminal appear on the screen one is the on we going to use in this Tele-operation function

Then you have to open another terminal and run this command line 
```
ros2 run saifa_pack teleop_turtle.py
```
to open another terminal like this
<br>

![image](https://github.com/user-attachments/assets/78d8a584-178c-4ec0-a389-433fcce5a2c8)

So this termianl is going to be use to control the turtle on the termminal ,

### Keyblind 
- w to go forward
- s to go backward
- a to rotate left
- d to rotate right
- e to stop moving
 ### warning: If you want to control the turtle you should left a click at the Teleoperation window all the time ###
 ##### (if you cannot control the turtle try to click at the terminal agian) ##### 
  ![image](https://github.com/user-attachments/assets/2ef03283-721a-4e66-956e-099f733f3c49)

  So we done the Tele-op base on that 
![image](https://github.com/user-attachments/assets/76410962-07cf-4850-90f3-2f5e63005003)
this Tele-op are going to be a node that going to input the pos or posiotion in the present of the t_name (turtle name)
and then control the velocity or acceletion of the turtle when it going to move to another pos  and we add a little help from 
the control parameter ,So the code that control the spped is going to look like tihs 

![image](https://github.com/user-attachments/assets/010c5b30-ad02-40df-afa3-d3f077fb1fa2)

and we use a little bit pythagoras theory to find a Distance betweeen point and robot 





  






