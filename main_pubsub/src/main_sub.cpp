#include <memory>
#include<iostream>
#include "main_pubsub/sub_lib.hpp"
#include "rclcpp/rclcpp.hpp"
using namespace std;

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<main_pubsub::MinimalSubscriber>();
  rclcpp::spin(node->get_node_base_interface());
  //rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}