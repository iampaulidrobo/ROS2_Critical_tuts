
# ROS2_Critical_tuts

The 6 package contains simple publisher/subsriber,service/client and action/server with default ROS2 codes and some custom enhancement for better understanding.  
UPON BUILDING,THERE WILL BE ERRORS FOR "d_servclient" and "d_actserver" BECAUSE OF CUSTOMISED ACTION AND SERVICE CREATION.{COMMENTIN AND OUT IN "CMAKEFILE LISTS" ALONG WITH THE PACKAGE NAME IN "find_package"}  
DON'T FORGET TO SOURCE THE WORKSPACE  



## d_pubsub

To deploy this package run:  
T-1
```bash
  ros2 run d_pubsub talker
```
T-2
```bash
  ros2 run d_pubsub listener
```
Both to work simultaneously using launch file:
```bash
  ros2 launch d_pubsub pubsub.launch.py 
```
## main_pubsub

To deploy this package run:  
T-1
```bash
  ros2 run main_pubsub main_pub
```
T-2
```bash
  ros2 run main_pubsub main_sub
```
## d_servclient

To deploy this package run:  
T-1
```bash
  ros2 run d_servclient server
```
T-2
```bash
  ros2 run d_servclient client 1 2
```
Customised ServiceClient:  
T-1
```bash
  ros2 run d_servclient server_renew 
```
T-2
```bash
  ros2 run d_servclient client_renew 1 2
```
## d_actserver

To deploy this package run:  
T-1
```bash
  ros2 run d_actserver fibonacci_action_server
```
T-2
```bash
  ros2 run d_actserver fibonacci_action_client
```
Customised ActionServer:  
T-1
```bash
  ros2 run d_actserver NSum_action_server 
```
T-2
```bash
  ros2 run d_actserver NSum_action_client
```
## cross_pubsub

To deploy this package run:  
T-1
```bash
  ros2 run cross_pubsub cross_pubsub
```


