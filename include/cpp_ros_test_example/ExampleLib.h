#pragma once
#ifndef EXAMPLE_LIB_INCLUDE
#define EXAMPLE_LIB_INCLUDE


namespace cpp_ros_test_example {
    class Counter {
        public:
        void next();
        void previous();
        int get();

        private:
        int counter;
    };
};


#endif