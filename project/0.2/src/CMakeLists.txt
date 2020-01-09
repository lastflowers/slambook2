# generate shared library named "myslam" from *.ccps 
add_library( myslam SHARED
    frame.cpp
    mappoint.cpp
    map.cpp
    camera.cpp
    config.cpp
    visual_odometry.cpp
)

# link myslam to the thrid party libs defined in ../CMakeLists.txt
target_link_libraries( myslam
    ${THIRD_PARTY_LIBS}
)
