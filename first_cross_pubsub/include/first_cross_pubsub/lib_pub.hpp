#include <chrono>
#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
namespace first_cross_pubsub
{

  class MinimalPublisher : public rclcpp::Node
  {
  public:
    MinimalPublisher();
    void timer_callback();
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;
    int test_demo = 0;
    void test_demoo();
  };

}
