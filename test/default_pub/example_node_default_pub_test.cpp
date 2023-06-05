#include <gtest/gtest.h>

#include "ros/ros.h"
#include "std_msgs/Int32.h"

TEST(TestExampleNodeDefaultPub, default_pub) {
    ros::NodeHandle nh("example_node");
    auto timeout = ros::Duration().fromSec(1);
    auto val = ros::topic::waitForMessage<std_msgs::Int32>("value", nh, timeout)->data;

    EXPECT_EQ(val, 0);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    ros::init(argc, argv, "example_node_default_pub", ros::init_options::AnonymousName);
    return RUN_ALL_TESTS();
}
