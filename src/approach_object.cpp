#include "bt_cpp_demo/approach_object.hpp"

ApproachObject::ApproachObject(const std::string &name)
  : SyncActionNode(name, {}) {}

NodeStatus ApproachObject::tick()
{
  std::cout << "Approach Object: " << this->name() << std::endl;
  std::this_thread::sleep_for(5s);
  return NodeStatus::SUCCESS;
}
