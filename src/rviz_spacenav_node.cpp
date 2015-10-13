//Include the base of rviz_spacenav
#include "rviz_spacenav/include/rviz_spacenav/rviz_spacenav.h"

using namespace std;

void SpacenavCallback(const sensor_msgs::Joy& msg)
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

    // start processing callbacks
    while(ros::ok() && !quit_)
    {
        ros::spinOnce();
    }
    ROS_INFO("rviz_spacenav node stopped.");

    return EXIT_SUCCESS;
}
