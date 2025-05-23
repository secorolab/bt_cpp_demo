#pragma once

#include <behaviortree_cpp/action_node.h>
#include <iostream>

// Declaration of a custom function. This function can be registered as a condition node in the Behavior Tree
BT::NodeStatus CheckBattery();
