#include <chrono>
#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
namespace main_pubsub
{

  class MinimalSubscriber : public rclcpp::Node
  {
  public:
    MinimalSubscriber();

  private:
    void topic_callback(const std_msgs::msg::String::SharedPtr msg) const;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
  };

}
