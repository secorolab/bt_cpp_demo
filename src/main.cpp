#include "behaviortree_cpp/bt_factory.h"
#include "bt_cpp_demo/approach_object.hpp"
#include "bt_cpp_demo/check_battery.hpp"
#include "bt_cpp_demo/gripper_interface.hpp"
#include "behaviortree_cpp/loggers/bt_observer.h"
#include "behaviortree_cpp/xml_parsing.h"
#include "behaviortree_cpp/loggers/groot2_publisher.h"
#include <fstream>
#include <tinyxml2.h>

int main()
{
  // Initialize the Behavior Tree Factory
  BT::BehaviorTreeFactory factory;

  // Register custom nodes using registerNodeType
  factory.registerNodeType<ApproachObject>("ApproachObject");

  // Register a condition node using registerSimpleCondition. If the condition is a class, then register it as a custom node
  factory.registerSimpleCondition("CheckBattery", std::bind(CheckBattery));

  // Register simple action nodes using registerSimpleAction
  // The callback can be a member function bound to an object instance
  GripperInterface gripper;

  factory.registerSimpleAction(
      "OpenGripper",                                  // ID of the action node used in the XML file
      std::bind(&GripperInterface::open, &gripper));  // Callback function to be executed when the node is ticked

  factory.registerSimpleAction(
      "CloseGripper",                                 // ID of the action node used in the XML file
      std::bind(&GripperInterface::close, &gripper)); // Callback function to be executed when the node is ticked

  // create xml models to load bt to Groot2
  std::string xml_models = BT::writeTreeNodesModelXML(factory);

  // Load the XML file that defines the Behavior Tree structure
  auto tree = factory.createTreeFromFile("./config/my_tree.xml");

  // save the XML models to a file
  std::ofstream xml_file("./config/my_tree_groot.xml");
  if (!xml_file.is_open()) {
    std::cerr << "Failed to open file for writing: my_tree_groot.xml" << std::endl;
    return 1;
  }
  xml_file << xml_models;
  xml_file.close();

  // Logging to terminal

  // The purpose of the observer is to save some statistics about the number of times
  // a certain node returns SUCCESS or FAILURE
  BT::TreeObserver observer(tree);

  // Print the unique ID and the corresponding human readable path
  // Path is also expected to be unique
  std::map<uint16_t, std::string> ordered_UID_to_path;
  for(const auto& [name, uid]: observer.pathToUID()) {
    ordered_UID_to_path[uid] = name;
  }

  for(const auto& [uid, name]: ordered_UID_to_path) {
    std::cout << uid << " -> " << name << std::endl;
  }
  
  // tick the tree continuously
  tree.tickWhileRunning();

  std::cout << "----------------" << std::endl;
  // print all the statistics
  for(const auto& [uid, name]: ordered_UID_to_path) {
    const auto& stats = observer.getStatistics(uid);

    std::cout << "[" << name
              << "] \tT/S/F:  " << stats.transitions_count
              << "/" << stats.success_count
              << "/" << stats.failure_count
              << std::endl;
  }

  return 0;
}
