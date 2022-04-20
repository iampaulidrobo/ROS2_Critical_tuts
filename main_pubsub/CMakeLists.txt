cmake_minimum_required(VERSION 3.5)
project(main_pubsub)

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
find_package(std_msgs REQUIRED)
###################################################################################################################################################
include_directories(
  include
)
###################################################################################################################################################
set(library_name libpub)
set(library_name_ libsub)
set(executable_name main_pub)
set(executable_name_ main_sub)
###################################################################################################################################################
set(dependencies
  rclcpp
  std_msgs
)
###################################################################################################################################################
add_library(${library_name}
  src/pub_lib.cpp
)
ament_target_dependencies(${library_name}
  ${dependencies}
)

add_library(${library_name_}
  src/sub_lib.cpp
)

ament_target_dependencies(${library_name_}
  ${dependencies}
)

###################################################################################################################################################
add_executable(${executable_name}
  src/main_pub.cpp
)
target_link_libraries(${executable_name} ${library_name})
ament_target_dependencies(${executable_name}
  ${dependencies}
)

add_executable(${executable_name_}
  src/main_sub.cpp
)
target_link_libraries(${executable_name_} ${library_name_})
ament_target_dependencies(${executable_name_}
  ${dependencies_}
)
###################################################################################################################################################
install(TARGETS ${library_name}  ${library_name_}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)
###################################################################################################################################################
install(TARGETS ${executable_name} ${executable_name_}
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)
###################################################################################################################################################
install(DIRECTORY include/
  DESTINATION include/
)
###################################################################################################################################################

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
