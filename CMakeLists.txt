project(SmallestCircle)

cmake_minimum_required (VERSION 2.8.3)

# -g allows for gdb debugging
# turn on -03 for best performance
add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

include_directories(
	include/SmallestCircle
)

set(sources 
)

add_executable(SmallestCircle ${sources})
