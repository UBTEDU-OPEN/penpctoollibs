cmake_minimum_required(VERSION 3.2)
project(portlib)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
# set(CMAKE_BUILD_TYPE "Release")
add_definitions(-DPORTLIB_EXPORTS)

add_library(portlib SHARED platformport.cpp httpconfig.cpp)
