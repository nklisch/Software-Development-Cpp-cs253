cmake_minimum_required(VERSION 3.14)

# Using -Wall is required:
add_compile_options(-Wall -O3)

# These compile flags are highly recommended, but not required:

# Optional super-strict mode:

# add_compile_options must be BEFORE add_executable or add_library.

add_library(hw8 Enemy.cc Utilities.cc Gallery.cc)
add_executable(test test.cc)
target_link_libraries(test hw8)

# Create a tar file every time:
add_custom_target(hw8.tar ALL COMMAND tar cf hw8.tar *.cc *.h CMakeLists.txt)
