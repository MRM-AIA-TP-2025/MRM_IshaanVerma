// chat_talker.cpp
#include "ros/ros.h"
#include "chatroom/ChatMessage.h"

int main(int argc, char **argv)//main function with argument count and argument vector
{
  ros::init(argc, argv, "chat_talker");//initialize the ROS system and name of the node "chat_talker"
  ros::NodeHandle n;//creating a nodehandle 'n' to communicate with the ROS system
  ros::Publisher chat_pub = n.advertise<chatroom::ChatMessage>("chat", 1000);//creates a publisher named 'chat_pub'. Initializes the publisher using advertise function with the chat type 'ChatMessage'. "chat" is the ROS Topic. 1000 is the message queue size. publisher chat_pub will send messages of type 'ChatMessage' to the "chat" topic.
  ros::Rate loop_rate(1);//rate of the main loop=1hz

  while (ros::ok())//to check if ROS system is still operational
  {
    chatroom::ChatMessage msg;//creating a ChatMessage object to store user data
    std::cout << "Enter your username: ";
    std::getline(std::cin, msg.username);
    std::cout << "Enter your message: ";
    std::getline(std::cin, msg.content);

    chat_pub.publish(msg);//puublishes the Chatmessage object "msg" to the topic "chat"
    ros::spinOnce();//processes ny callbacks
    loop_rate.sleep();
  }

  return 0;
}
