//Include the base of rviz_spacenav
#include "rviz_spacenav/include/rviz_spacenav/rviz_spacenav.h"

using namespace std;

void SpacenavCallback(const geometry_msgs::Twist& msg)
{
}

void GetParameterValues()
{
    // Load node-wide configuration values.
    // node_->param ("option",     option_, std::string(""));
}

void SetupSubscriber()
{
    spacenav_subscriber_ = (*node_).subscribe(
                DEFAULT_SPACENAV_TOPIC, 10, &SpacenavCallback);
    running_ = true;
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
    SetupSubscriber();

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
