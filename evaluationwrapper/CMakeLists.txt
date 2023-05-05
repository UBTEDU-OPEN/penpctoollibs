cmake_minimum_required(VERSION 3.2)
project(evaluationwrapper)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
# set(CMAKE_BUILD_TYPE "Release")
add_definitions(-DEVALUATION_WRAPPER_EXPORTS)

add_library(evaluationwrapper SHARED evaluationserializer.cpp charevaluationwrapper.cpp)

target_include_directories(evaluationwrapper PUBLIC 
                            ../trd/jsoncpp/include)
target_link_directories(evaluationwrapper PUBLIC 
                        ../trd/jsoncpp/lib/win32/release)
target_link_libraries(evaluationwrapper PUBLIC jsoncpp)
