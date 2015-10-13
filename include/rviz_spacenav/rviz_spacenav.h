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


// Define the default topic names
const std::string DEFAULT_SPACENAV_TOPIC = "spacenav/twist";

// ROS parts
ros::NodeHandlePtr node_;

// ROS Publishers and Subscribers
ros::Subscriber spacenav_subscriber_;

// Settings and global information
bool running_;
bool quit_;

// Package Functions

// Callback for new image
void SpacenavCallback(const geometry_msgs::Twist& msg);

// Read Parameters for unsubcription
void GetParameterValues();

// Advertize Publishers
void SetupPublisher();

// Initialize the ROS Node
void InitializeROSNode();

#endif // RVIZ_SPACENAV_H
