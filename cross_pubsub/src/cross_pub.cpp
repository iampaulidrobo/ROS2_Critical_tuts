#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "first_cross_pubsub/lib_pub.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  //rclcpp::spin(std::make_shared<publisher_sub_with_main::stringpublisher>());           
  first_cross_pubsub::MinimalPublisher classobj;  
  classobj.test_demoo();
  rclcpp::shutdown();
  return 0;
}