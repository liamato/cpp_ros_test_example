#include <gtest/gtest.h>

#include "cpp_ros_test_example/ExampleLib.h"

using cpp_ros_test_example::Counter;

TEST(Counter, defaultConstructor) {
    Counter c;
    EXPECT_EQ(c.get(), 0);
}

TEST(Counter, next) {
    Counter c;
    c.next();
    EXPECT_EQ(c.get(), 1);
    c.next();
    EXPECT_EQ(c.get(), 2);
    c.next();
    c.next();
    EXPECT_EQ(c.get(), 4);
}

TEST(Counter, previous) {
    Counter c;
    c.previous();
    EXPECT_EQ(c.get(), -1);
    c.previous();
    EXPECT_EQ(c.get(), -2);
    c.previous();
    c.previous();
    EXPECT_EQ(c.get(), -4);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
