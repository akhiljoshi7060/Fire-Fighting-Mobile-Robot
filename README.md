# 🔥 Fire-Fighting Robot

A mobile autonomous robot equipped with a 4-DOF flame-tracking robotic arm and PID-controlled movement. Designed to detect, track, and extinguish small fires with an 85% flame detection accuracy in real-world testing.

---

## 🚀 Overview

This project demonstrates a fire-fighting robot designed for environments where autonomous fire detection and suppression is critical, such as smart buildings, labs, and hazardous industrial zones.

Key Features:

* 🔍 **4-DOF Flame-Tracking Arm**
* 📱 **PID-Based Motion Control**
* 🤖 **Mobile Robot Base with Obstacle Avoidance**
* 🔥 **85% Flame Detection Accuracy**
* 💧 **Fire Extinguishing Mechanism**

---

## 🛠️ System Architecture

### 1. **Mobile Base**

* 2-wheel differential drive with caster for balance
* Controlled via PID loop for accurate path following
* IR and ultrasonic sensors for obstacle avoidance

### 2. **Robotic Arm**

* 4 Degrees of Freedom
* Flame tracking using an IR sensor array mounted on the end-effector
* Arm movement controlled via inverse kinematics

### 3. **Sensors**

* IR flame sensor array
* Ultrasonic distance sensors (for obstacle detection)
* Temperature sensors (optional)

### 4. **Fire Extinguisher**

* Small CO₂ or water-based mechanism mounted at the gripper
* Activated once flame is within range and confirmed

---

## 📦 Project Structure

```bash
FireFighterRobot/
├── src/                         # Source code for control nodes
│   ├── arm_controller.py
│   ├── flame_tracker.py
│   └── pid_controller.py
├── launch/
│   └── fire_fighting_sim.launch
├── urdf/                        # Robot description (URDF/XACRO)
│   └── fire_robot.urdf.xacro
├── config/                      # PID parameters, sensor config
├── worlds/
│   └── fire_world.world         # Custom Gazebo simulation world
├── meshes/
├── scripts/
│   └── test_flame_tracking.py
├── CMakeLists.txt
├── package.xml
└── README.md
```

---

## 🧠 How It Works

1. The robot roams the environment using obstacle avoidance.
2. The flame sensor array continuously scans for heat signatures.
3. Upon detecting a flame:

   * The robot stops and aligns the arm.
   * The 4-DOF arm uses IK and PID to position the nozzle.
   * The extinguishing mechanism is triggered.
4. Robot resumes patrol after extinguishing.

---

## ⚙️ Dependencies

* ROS (Noetic recommended)
* Gazebo (for simulation)
* `ros_control`, `joint_state_controller`, `effort_controllers`
* `robot_state_publisher`, `tf`, `rviz`, `xacro`

Install dependencies:

```bash
sudo apt-get install ros-noetic-joint-state-controller ros-noetic-effort-controllers
```

---

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

---

## ✅ Performance

* **Flame Detection Accuracy**: 85% (tested across 40 scenarios)
* **Reaction Time**: ~2s from detection to nozzle alignment
* **Obstacle Avoidance Success Rate**: ~90%

---

## 📸 Demo

*Coming soon: video link or screenshots from RViz/Gazebo*

---

## 📄 .gitignore Notes

This project’s `.gitignore` includes standard ROS build artifacts, log files, and editor-specific metadata (from Qt Creator, Eclipse, etc.) to keep the repo clean.
