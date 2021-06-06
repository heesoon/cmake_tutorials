cmake_minimum_required(VERSION 3.10)

# set the project name
project(tutorial3 CXX) 	# PROJECT_NAME is tutorial3

# set makefile verbose enable
SET(CMAKE_VERBOSE_MAKEFILE ON)

# add library (default static library)
add_library(

)

# add the executable
add_executable(${PROJECT_NAME} tutorial3.cpp)

# set path for libary
target_link_libraries(${PROJECT_NAME} PRIVATE
)
