# ROS2_Critical_tuts
 The 6 packages contains simple publisher/subsriber,service/client and action/server with default ROS2 codes and some custom enhancement for better understanding.
UPON BUILDING,THERE WILL BE ERRORS FOR "d_servclient" and "d_actserver" BECAUSE OF CUSTOMISED ACTION AND SERVICE CREATION.{COMMENTIN AND OUT IN "CMAKEFILE LISTS" ALONG WITH THE PACKAGE NAME IN "find_package"}
DON'T FORGET TO SOURCE THE WORKSPACE
# d_pubsub
1)ros2 run d_pubsub talker
2)ros2 run d_pubsub listener 
3)ros2 launch d_pubsub pubsub.launch.py
# main_pubsub
1)ros2 run main_pubsub main_pub
2) ros2 run main_pubsub main_sub
# d_servclient
1)ros2 run d_servclient server
2)ros2 run d_servclient client 1 2

1)ros2 run d_servclient server_renew 
2)ros2 run d_servclient client_renew 1 2
# d_actserver
1)ros2 run d_actserver fibonacci_action_server
2)ros2 run d_actserver fibonacci_action_client

1)ros2 run d_actserver NSum_action_server
2)ros2 run d_actserver NSum_action_client
# cross_pubsub
1)ros2 run cross_pubsub cross_pubsub 

