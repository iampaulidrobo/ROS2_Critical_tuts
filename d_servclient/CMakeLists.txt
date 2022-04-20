cmake_minimum_required(VERSION 3.5)
project(d_servclient)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(d_servclient REQUIRED)
find_package(rosidl_default_generators REQUIRED)
###################################################################################################################################################
#custom service created
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/MultiplyTwoInt.srv"
 )

#############################COMMENT IN######################################################################################################################
add_executable(server src/server_service.cpp)
ament_target_dependencies(server
rclcpp example_interfaces)

add_executable(client src/server_client.cpp)
ament_target_dependencies(client
  rclcpp example_interfaces)

add_executable(server_renew src/server_service_renew.cpp)
ament_target_dependencies(server_renew
rclcpp d_servclient)

add_executable(client_renew src/server_client_renew.cpp)
ament_target_dependencies(client_renew
  rclcpp d_servclient)
###################################################################################################################################################
install(TARGETS
  server
  client
  server_renew
  client_renew
  DESTINATION lib/${PROJECT_NAME})
##############################################COMMENTOUT#####################################################################################################
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()