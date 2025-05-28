# BehaviorTree.CPP Minimal Example

This repository contains a minimal working example using the [BehaviorTree.CPP](https://github.com/BehaviorTree/BehaviorTree.CPP) library. It serves as a foundational setup to explore and run tutorials from the official documentation. Similar example for using BehaviorTree in ROS2 ecosystem can be found [here](https://github.com/secorolab/bt_ros2_demo/tree/master).

## Setup & Build

### Prerequisites

- CMake (>= 3.10)
- A C++ compiler (e.g., g++ or clang++)
- BehaviorTree.CPP library (installed or available as a submodule)
- If using ROS Jazzy, it can also be installed via apt package manager:
  ```bash
  sudo apt install ros-jazzy-behaviortree-cpp
  
### Build Instructions
- From the same level as src/ folder, build the package
  ```bash
  cmake -Bbuild
  cmake --build build
  ```

- Execute by running: 
  ```bash
  ./build/bt_cpp_demo`
  ```

### Visualisation in Groot2

To visualize the generated XML in Groot2, open the generated file (e.g., my_tree_groot.xml) and:  
- Copy the contents of your original tree definition file (e.g., my_tree.xml), excluding the outer `<root>` tags
- Paste that content just before the `<TreeNodesModel>` element inside the <root> tag in the generated XML

This will result in a combined XML containing both the `<BehaviorTree>` definition and the `<TreeNodesModel>`, which can be loaded directly into Groot2 for visualization.

To view the behavior tree ticking in real time, under the *Real-time Monitor Mode*, set the port number as 1667.
 
**Note:** Installation instructions of Groot2 can be found [here](https://www.behaviortree.dev/groot/).
