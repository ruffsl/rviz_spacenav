//Include the base of rviz_spacenav
#include "rviz_spacenav/include/rviz_spacenav/rviz_spacenav.h"

using namespace std;

void SpacenavCallback(const geometry_msgs::Twist& msg)
{
}


void ConnectCallback(const ros::SingleSubscriberPublisher& info)
{
    // Check for subscribers.
    uint32_t subscribers = rviz_publisher_.getNumSubscribers();
    ROS_DEBUG("Subscription detected! (%d subscribers)", subscribers);

    if(subscribers && !running_)
    {
        ROS_DEBUG("New Subscribers, Connecting to Spacenav Topic.");
        spacenav_subscriber_ = (*node_).subscribe(
                    DEFAULT_SPACENAV_TOPIC, 10, &SpacenavCallback);
        running_ = true;
    }
}

void DisconnectCallback(const ros::SingleSubscriberPublisher& info)
{
    // Check for subscribers.
    uint32_t subscribers = rviz_publisher_.getNumSubscribers();
    ROS_DEBUG("Unsubscription detected! (%d subscribers)", subscribers);

    if(!subscribers && running_)
    {
        ROS_DEBUG("No Subscribers, Disconnecting from Input Spacenav Topic.");
        spacenav_subscriber_.shutdown();
        running_ = false;
    }
}

void DisconnectHandler()
{
}

void GetParameterValues()
{
    // Load node-wide configuration values.
    // node_->param ("option",     option_, std::string(""));
}

void SetupPublisher()
{
    // Add callbacks
    ros::SubscriberStatusCallback connect_callback = &ConnectCallback;
    ros::SubscriberStatusCallback disconnect_callback = &DisconnectCallback;

    // Publisher
    rviz_publisher_ = node_->advertise<view_controller_msgs::CameraPlacement>(
                DEFAULT_RVIZ_TOPIC, 1, connect_callback, disconnect_callback);
}

void InitializeROSNode(int argc, char **argv)
{
    ros::init(argc, argv, "rviz_spacenav");
    node_ =  boost::make_shared<ros::NodeHandle>("~");

}

int main(int argc, char **argv)
{
    // Initialize Node
    InitializeROSNode(argc,argv);
    GetParameterValues();
    SetupPublisher();

    // Start Node
    ROS_INFO("rviz_spacenav node started.");
    running_ = false;

//    dynamic_reconfigure::Server<Config> server;
//    dynamic_reconfigure::Server<Config>::CallbackType f;
//    f = boost::bind(&ParameterCallback, _1, _2);
//    server.setCallback(f);

    // start processing callbacks
    while(ros::ok() && !quit_)
    {
        ros::spinOnce();
    }
    ROS_INFO("rviz_spacenav node stopped.");

    return EXIT_SUCCESS;
}
