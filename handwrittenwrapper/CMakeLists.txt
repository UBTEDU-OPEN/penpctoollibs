cmake_minimum_required(VERSION 3.2)
project(handwrittenwrapper)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
# set(CMAKE_BUILD_TYPE "Release")
add_definitions(-DHAND_WRITTEN_WRAPPER_EXPORTS)

add_library(handwrittenwrapper SHARED handwrittenwrapper.cpp)
