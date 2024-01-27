// chat_listener.cpp
#include "ros/ros.h"//header files
#include "chatroom/ChatMessage.h"
#include "chatroom/ChatService.h"

void chatCallback(const chatroom::ChatMessage::ConstPtr &msg)//callback function that will be executed whenever a new message is received on the "chat" topic
{
  cout<<("Listener: %s - %s", msg->username.c_str(), msg->content.c_str());//informational message prints on the ROS log. It shows the username and content of the received message
}

int main(int argc, char **argv)//setup of ROS environment for listener node
{
  ros::init(argc, argv, "chat_listener");//initilaizes the ROS system and node name is chat_listener
  ros::NodeHandle n;//creating a NodeHandle object used to communicate with the ROS system
  ros::Subscriber chat_sub = n.subscribe("chat", 1000, chatCallback);//Creating a subscriber that listens to the "chat" topic and calls the chatCallback function

  ros::spin();//function that enters a loop that waits for messages to arrive and triggers the callback function when message is received

  return 0;
}
