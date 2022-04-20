#include <chrono>
#include <memory>
#include "first_cross_pubsub/lib_pub.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;
namespace first_cross_pubsub
{
  MinimalPublisher::MinimalPublisher() : Node("minimal_publisher"), count_(0)
  {
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    timer_ = this->create_wall_timer(500ms, std::bind(&MinimalPublisher::timer_callback, this));
  }

  void MinimalPublisher::timer_callback()
  {
    test_demo++;
    auto message = std_msgs::msg::String();
    message.data = "Hello, world! " + std::to_string(count_++);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
  }
  void MinimalPublisher::test_demoo()
  {
    RCLCPP_INFO(this->get_logger(), "HELLO");
  }

} // namespace first_cross_pubsub