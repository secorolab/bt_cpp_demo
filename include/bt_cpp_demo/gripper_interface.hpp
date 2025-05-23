#pragma once

#include <behaviortree_cpp/action_node.h>
#include <iostream>

class GripperInterface
{
public:
  GripperInterface();

  // these functions can be registered as separate action nodes in the Behavior Tree, given that they return a NodeStatus
  BT::NodeStatus open();
  BT::NodeStatus close();

private:
  bool _open;
};
