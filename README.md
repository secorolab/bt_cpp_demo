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
