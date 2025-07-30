cmake_minimum_required(VERSION 3.26)
project(PriorityQueues)

set(CMAKE_CXX_STANDARD 17)

add_executable(PriorityQueues main.cpp
        shp_priority_queue.cpp
        shp_priority_queue.h)
