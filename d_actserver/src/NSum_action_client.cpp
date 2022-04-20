#include <functional>
#include <future>
#include <memory>
#include <string>
#include <sstream>

#include "d_actserver/action/n_sum.hpp"

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

namespace d_actserver
{
  class FibonacciActionClient : public rclcpp::Node
  {
  public:
    using NSum = d_actserver::action::NSum;
    using GoalHandleNSum = rclcpp_action::ClientGoalHandle<NSum>;

    FibonacciActionClient()
        : Node("NSum_action_client")
    {
      this->client_ptr_ = rclcpp_action::create_client<NSum>(
          this,
          "NSum");

      this->timer_ = this->create_wall_timer(
          std::chrono::milliseconds(500),
          std::bind(&FibonacciActionClient::send_goal, this));
    }

    void send_goal()
    {
      using namespace std::placeholders;

      this->timer_->cancel();

      if (!this->client_ptr_->wait_for_action_server())
      {
        RCLCPP_ERROR(this->get_logger(), "Action server not available after waiting");
        rclcpp::shutdown();
      }

      auto goal_msg = NSum::Goal();
      goal_msg.n = 10;

      RCLCPP_INFO(this->get_logger(), "Sending goal");

      auto send_goal_options = rclcpp_action::Client<NSum>::SendGoalOptions();
      send_goal_options.goal_response_callback =
          std::bind(&FibonacciActionClient::goal_response_callback, this, _1);
      send_goal_options.feedback_callback =
          std::bind(&FibonacciActionClient::feedback_callback, this, _1, _2);
      send_goal_options.result_callback =
          std::bind(&FibonacciActionClient::result_callback, this, _1);
      this->client_ptr_->async_send_goal(goal_msg, send_goal_options);
    }

  private:
    rclcpp_action::Client<NSum>::SharedPtr client_ptr_;
    rclcpp::TimerBase::SharedPtr timer_;

    void goal_response_callback(std::shared_future<GoalHandleNSum::SharedPtr> future)
    {
      auto goal_handle = future.get();
      if (!goal_handle)
      {
        RCLCPP_ERROR(this->get_logger(), "Goal was rejected by server");
      }
      else
      {
        RCLCPP_INFO(this->get_logger(), "Goal accepted by server, waiting for result");
      }
    }

    void feedback_callback(
        GoalHandleNSum::SharedPtr,
        const std::shared_ptr<const NSum::Feedback> feedback)
    {
      std::stringstream ss;
      ss << "Next number in sequence received: ";
      for (auto number : feedback->n_partial_sum)
      {
        ss << number << " ";
      }
      RCLCPP_INFO(this->get_logger(), ss.str().c_str());
    }

    void result_callback(const GoalHandleNSum::WrappedResult &result)
    {
      switch (result.code)
      {
      case rclcpp_action::ResultCode::SUCCEEDED:
        break;
      case rclcpp_action::ResultCode::ABORTED:
        RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
        return;
      case rclcpp_action::ResultCode::CANCELED:
        RCLCPP_ERROR(this->get_logger(), "Goal was canceled");
        return;
      default:
        RCLCPP_ERROR(this->get_logger(), "Unknown result code");
        return;
      }
      std::stringstream ss;
      ss << "Result received: ";
      for (auto number : result.result->n_sum)
      {
        ss << number << " ";
      }
      RCLCPP_INFO(this->get_logger(), ss.str().c_str());
      rclcpp::shutdown();
    }
  }; // class FibonacciActionClient

} // namespace d_actserver

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<d_actserver::FibonacciActionClient>());
  rclcpp::shutdown();
  return 0;
}