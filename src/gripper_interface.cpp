#include "bt_cpp_demo/gripper_interface.hpp"

GripperInterface::GripperInterface() : _open(true) {}

BT::NodeStatus GripperInterface::open()
{
  _open = true;
  std::cout << "Gripper open" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus GripperInterface::close()
{
  _open = false;
  std::cout << "Gripper close" << std::endl;
  return BT::NodeStatus::SUCCESS;
}
