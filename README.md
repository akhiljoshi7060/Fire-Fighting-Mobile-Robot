# 🔥 Fire-Fighting Robot

A mobile autonomous robot equipped with a 4-DOF flame-tracking robotic arm and PID-controlled movement. Designed to detect, track, and extinguish small fires with an 85% flame detection accuracy in real-world testing.

## ⚙️ Dependencies

* ROS (Noetic recommended)
* Gazebo (for simulation)
* `ros_control`, `joint_state_controller`, `effort_controllers`
* `robot_state_publisher`, `tf`, `rviz`, `xacro`

Install dependencies:

```bash
sudo apt-get install ros-noetic-joint-state-controller ros-noetic-effort-controllers
```
## 🧪 Simulation Setup (Gazebo)

1. Clone the repository into your Catkin workspace:

```bash
cd ~/catkin_ws/src
git clone <this_repo_url>
cd ..
catkin_make
source devel/setup.bash
```

2. Launch the simulation:

```bash
roslaunch fire_fighting_robot fire_fighting_sim.launch
```

3. In RViz or Gazebo, use keyboard or autonomous node to start patrol.

---

## 📈 PID Control Tuning

PID parameters can be configured in `config/pid_params.yaml`:

```yaml
Kp: 1.2
Ki: 0.01
Kd: 0.4
```

Adjust as per the robot's response to reach optimal tracking and movement smoothness.
