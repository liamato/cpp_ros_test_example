#include <ros/ros.h>

#include "std_msgs/Int32.h"
#include "std_srvs/Trigger.h"

#include "cpp_ros_test_example/ExampleLib.h"


using std_srvs::Trigger;

int main(int argc, char* argv[]) {
    ros::init(argc, argv, "cpp_ros_test_example_node");
    auto counter_instance = cpp_ros_test_example::Counter();

    ros::NodeHandle nh {"~"};

    auto next_srv = nh.advertiseService<Trigger::Request, Trigger::Response>(
        "next", [&counter_instance](Trigger::Request& req, Trigger::Response& res) -> bool {
            counter_instance.next();
            return true;
        });

    auto prev_srv = nh.advertiseService<Trigger::Request, Trigger::Response>(
        "previous", [&counter_instance](Trigger::Request& req, Trigger::Response& res) -> bool {
            counter_instance.previous();
            return true;
        });

    auto val_pub = nh.advertise<std_msgs::Int32>("value", 10);

    ros::Rate rate(5.0);

    while (ros::ok()) {
        std_msgs::Int32 val;
        val.data = counter_instance.get();

        val_pub.publish(val);

        ros::spinOnce();
        rate.sleep();
    }

    ros::spin();

    return 0;
}
