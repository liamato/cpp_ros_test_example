
#include "cpp_ros_test_example/ExampleLib.h"

namespace cpp_ros_test_example {

    void Counter::next() { ++counter; }
    void Counter::previous() { --counter; }
    int Counter::get() { return counter; }
};