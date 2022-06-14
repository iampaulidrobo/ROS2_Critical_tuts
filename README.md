
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
![Screenshot from 2022-06-14 21-18-27](https://user-images.githubusercontent.com/22745024/173621235-a2820c97-d3f9-43cb-8809-1102464ce31f.png)

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
![Screenshot from 2022-06-14 21-19-20](https://user-images.githubusercontent.com/22745024/173621477-4fb14a7a-0054-48ea-8b8b-a7ec2bc34229.png)

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
![Screenshot from 2022-06-14 21-19-47](https://user-images.githubusercontent.com/22745024/173621555-df9c04ee-3723-42a3-b08d-db5bfbb3c4f4.png)

Customised ActionServer:  
T-1
```bash
  ros2 run d_actserver NSum_action_server 
```
T-2
```bash
  ros2 run d_actserver NSum_action_client
```
![Screenshot from 2022-06-14 21-19-50](https://user-images.githubusercontent.com/22745024/173621564-f791a7b1-7f12-4fb4-86fd-4df5057d6154.png)

## cross_pubsub

To deploy this package run:  
T-1
```bash
  ros2 run cross_pubsub cross_pubsub
```
![Screenshot from 2022-06-14 21-20-23](https://user-images.githubusercontent.com/22745024/173621590-6c91cd32-6763-477d-83bc-7f38f4308843.png)


