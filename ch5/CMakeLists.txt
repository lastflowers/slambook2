cmake_minimum_required(VERSION 2.8)

#set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_BUILD_TYPE "Debug")
# Add c++ 11 standard support
set(CMAKE_CXX_FLAGS "-std=c++11 -O2")
# set(CMAKE_CXX_FLAGS "-std=c++11 -O0") # without optimization

# Eigen
include_directories("/usr/include/eigen3")

# Looking for OpenCV library
find_package(OpenCV REQUIRED)
# add header file
include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(imageBasics)
add_subdirectory(stereo)
add_subdirectory(rgbd)
