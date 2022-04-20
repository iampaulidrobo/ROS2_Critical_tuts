#include <chrono>
#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
namespace main_pubsub
{

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher();

private:
  void timer_callback();
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_;
};

}
