# BehaviorTree.CPP Minimal Example

This repository contains a minimal working example using the [BehaviorTree.CPP](https://github.com/BehaviorTree/BehaviorTree.CPP) library. It serves as a foundational setup to explore and run tutorials from the official documentation.

## Setup & Build

### Prerequisites

- CMake (>= 3.10)
- A C++ compiler (e.g., g++ or clang++)
- BehaviorTree.CPP library (installed or available as a submodule)
- If using ROS Jazzy:
  ```bash
  sudo apt install ros-jazzy-behaviortree-cpp
  
### Build Instructions

```bash
cmake -Bbuild
cmake --build build
```

Execute by running: `./build/bt_cpp_demo`
