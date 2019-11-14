# the min. version of cmake required
cmake_minimum_required(VERSION 2.8)

# declare cmake project
project(HelloSLAM)

# set compilation mode
set(CMAKE_BUILD_TYPE "Debug")

# Add an executable program
# Syntax: add_executable( program name source code file)
add_executable(helloSLAM helloSLAM.cpp)

# add hello library
add_library(hello libHelloSLAM.cpp)
# shared library
add_library(hello_shared SHARED libHelloSLAM.cpp)

# Add an executable program to call the function in the hello library
add_executable(useHello useHello.cpp)
# Link the library file to the executable
target_link_libraries(useHello hello_shared)
