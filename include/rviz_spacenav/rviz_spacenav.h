#ifndef RVIZ_SPACENAV_H
#define RVIZ_SPACENAV_H

//Include ROS libraries for node messages
#include <ros/ros.h>
#include <ros/package.h>
#include <ros/forwards.h>
#include <ros/single_subscriber_publisher.h>
#include <std_msgs/String.h>

//Include Boost tools for detection arrays and threads
#include <boost/thread.hpp>
#include <boost/make_shared.hpp>

#include "geometry_msgs/Twist.h"
#include "view_controller_msgs/CameraPlacement.h"


// Define the default topic names
const std::string DEFAULT_SPACENAV_TOPIC = "spacenav/twist";
const std::string DEFAULT_RVIZ_TOPIC     = "rviz/camera_placement";

// ROS parts
ros::NodeHandlePtr node_;

// ROS Publishers and Subscribers
ros::Publisher rviz_publisher_;
ros::Subscriber spacenav_subscriber_;

// Settings and global information
bool running_;
bool quit_;

// Package Functions

// Callback for new image
void SpacenavCallback(const geometry_msgs::Twist& msg);

// Callback for new subcription
void ConnectCallback(const ros::SingleSubscriberPublisher& info);

// Callback for unsubcription
void DisconnectCallback(const ros::SingleSubscriberPublisher& info);

// Handler for unsubcription
void DisconnectHandler();

// Read Parameters for unsubcription
void GetParameterValues();

// Advertize Publishers
void SetupPublisher();

// Initialize the ROS Node
void InitializeROSNode();

#endif // RVIZ_SPACENAV_H
