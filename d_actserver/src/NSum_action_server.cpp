#include <functional>
#include <memory>
#include <thread>

#include "d_actserver/action/n_sum.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

namespace d_actserver
{
  class FibonacciActionServer : public rclcpp::Node
  {
  public:
    using NSum = d_actserver::action::NSum;
    using GoalHandleNSum = rclcpp_action::ServerGoalHandle<NSum>;

    FibonacciActionServer()
        : Node("NSum_action_server")
    {
      using namespace std::placeholders;

      this->action_server_ = rclcpp_action::create_server<NSum>(
          this,
          "NSum",
          std::bind(&FibonacciActionServer::handle_goal, this, _1, _2),
          std::bind(&FibonacciActionServer::handle_cancel, this, _1),
          std::bind(&FibonacciActionServer::handle_accepted, this, _1));
    }

  private:
    rclcpp_action::Server<NSum>::SharedPtr action_server_;

    rclcpp_action::GoalResponse handle_goal(
        const rclcpp_action::GoalUUID &uuid,
        std::shared_ptr<const NSum::Goal> goal)
    {
      RCLCPP_INFO(this->get_logger(), "Received goal request with order %d", goal->n);
      (void)uuid;
      return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::CancelResponse handle_cancel(
        const std::shared_ptr<GoalHandleNSum> goal_handle)
    {
      RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
      (void)goal_handle;
      return rclcpp_action::CancelResponse::ACCEPT;
    }

    void handle_accepted(const std::shared_ptr<GoalHandleNSum> goal_handle)
    {
      using namespace std::placeholders;
      // this needs to return quickly to avoid blocking the executor, so spin up a new thread
      std::thread{std::bind(&FibonacciActionServer::execute, this, _1), goal_handle}.detach();
    }

    void execute(const std::shared_ptr<GoalHandleNSum> goal_handle)
    {
      RCLCPP_INFO(this->get_logger(), "Executing goal");
      rclcpp::Rate loop_rate(1);
      const auto goal = goal_handle->get_goal();
      auto feedback = std::make_shared<NSum::Feedback>();
      auto &sequence = feedback->n_partial_sum;

      auto result = std::make_shared<NSum::Result>();
      int sum = 0;

      for (int i = 1; (i < goal->n) && rclcpp::ok(); ++i)
      {
        // Check if there is a cancel request
        if (goal_handle->is_canceling())
        {
          result->n_sum = sequence;
          goal_handle->canceled(result);
          RCLCPP_INFO(this->get_logger(), "Goal canceled");
          return;
        }
        // Update sequence

        sum = sum + i;
        sequence.push_back(sum);
        // Publish feedback
        goal_handle->publish_feedback(feedback);
        RCLCPP_INFO(this->get_logger(), "Publish feedback");

        loop_rate.sleep();
      }

      // Check if goal is done
      if (rclcpp::ok())
      {
        result->n_sum = sequence;
        goal_handle->succeed(result);
        RCLCPP_INFO(this->get_logger(), "Goal succeeded");
      }
    }
  }; // class FibonacciActionServer

} // namespace d_actserver
int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<d_actserver::FibonacciActionServer>());
  rclcpp::shutdown();
  return 0;
}