cmake_minimum_required(VERSION 2.8)
project(useSophus)
set(CMAKE_CXX_FLAGS "-std=c++11")

# In order to use sophus, you need to find it using the find_package command
# find the header and library files of Sophus, it returns Sophus_INCLUDE_DIRS
find_package(Sophus REQUIRED)
include_directories(${Sophus_INCLUDE_DIRS})

# Eigen
include_directories("/usr/include/eigen3")
add_executable(useSophus useSophus.cpp)

add_subdirectory(example)
