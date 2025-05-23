#pragma once

#include <behaviortree_cpp/action_node.h>
#include <iostream>
#include <thread>
#include <chrono>

using namespace BT;
using namespace std::chrono_literals;

class ApproachObject : public SyncActionNode
{
public:
  explicit ApproachObject(const std::string &name);

  // tick function is called when the node is ticked. It should return the status of the node
  NodeStatus tick() override;
};