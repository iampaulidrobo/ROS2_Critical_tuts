#include "rclcpp/rclcpp.hpp"
#include "d_servclient/srv/multiply_two_int.hpp"

#include <memory>

void product(const std::shared_ptr<d_servclient::srv::MultiplyTwoInt::Request> request,
          std::shared_ptr<d_servclient::srv::MultiplyTwoInt::Response>      response)
{
  response->product = request->a * request->b;
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld",
                request->a, request->b);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->product);
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("multiply_two_ints_server");

  rclcpp::Service<d_servclient::srv::MultiplyTwoInt>::SharedPtr service =
    node->create_service<d_servclient::srv::MultiplyTwoInt>("multiply_two_ints", &product);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to multiply two ints.");

  rclcpp::spin(node);
  rclcpp::shutdown();
}