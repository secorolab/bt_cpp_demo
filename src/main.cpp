#include "behaviortree_cpp/bt_factory.h"
#include "bt_cpp_demo/approach_object.hpp"
#include "bt_cpp_demo/check_battery.hpp"
#include "bt_cpp_demo/gripper_interface.hpp"

int main()
{
  // Initialize the Behavior Tree Factory
  BT::BehaviorTreeFactory factory;

  // Register custom nodes using registerNodeType
  factory.registerNodeType<ApproachObject>("ApproachObject");

  // Register a condition node using registerSimpleCondition. If the condition is a class, then register it as a custom node
  factory.registerSimpleCondition("CheckBattery", std::bind(CheckBattery));

  // Register simple action nodes using registerSimpleAction.
  // The callback can be a member function bound to an object instance.
  GripperInterface gripper;

  factory.registerSimpleAction(
      "OpenGripper",                                  // ID of the action node used in the XML file
      std::bind(&GripperInterface::open, &gripper));  // Callback function to be executed when the node is ticked

  factory.registerSimpleAction(
      "CloseGripper",                                 // ID of the action node used in the XML file
      std::bind(&GripperInterface::close, &gripper)); // Callback function to be executed when the node is ticked

  // Load the XML file that defines the Behavior Tree structure
  auto tree = factory.createTreeFromFile("./../config/my_tree.xml");

  // tick the tree continuously
  tree.tickWhileRunning();

  return 0;
}
