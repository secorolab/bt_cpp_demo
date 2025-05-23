cmake_minimum_required(VERSION 3.10)

project(bt_cpp_demo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(behaviortree_cpp REQUIRED)

include_directories(include)
# Define the executable
add_executable(${PROJECT_NAME} 
              src/main.cpp
              src/approach_object.cpp
              src/check_battery.cpp
              src/gripper_interface.cpp)

# Link against the BehaviorTree.CPP library
target_link_libraries(${PROJECT_NAME} PRIVATE behaviortree_cpp::behaviortree_cpp)
