#include <gtest/gtest.h>

#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_srvs/Trigger.h"

TEST(TestExampleNodePrevSrv, previous_service) {
    ros::NodeHandle nh("example_node");
    auto timeout = ros::Duration().fromSec(1);
    ros::ServiceClient next = nh.serviceClient<std_srvs::Trigger>("previous");

    EXPECT_TRUE(next.waitForExistence(timeout));

    std_srvs::Trigger trigger;

    EXPECT_TRUE(next.call(trigger));
    auto val = ros::topic::waitForMessage<std_msgs::Int32>("value", nh, timeout)->data;
    EXPECT_EQ(val, -1);

    EXPECT_TRUE(next.call(trigger));
    val = ros::topic::waitForMessage<std_msgs::Int32>("value", nh, timeout)->data;
    EXPECT_EQ(val, -2);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    ros::init(argc, argv, "example_node_prev_srv", ros::init_options::AnonymousName);
    return RUN_ALL_TESTS();
}
