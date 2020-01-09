add_executable( run_vo run_vo.cpp )

# link the executable named "run_vo" to the shared library named "myslam"
target_link_libraries( run_vo myslam )