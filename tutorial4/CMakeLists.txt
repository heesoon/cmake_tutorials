cmake_minimum_required(VERSION 3.10)

# set the project name
project(tutorial4 CXX)

# set makefile verbose enable
SET(CMAKE_VERBOSE_MAKEFILE ON)

# add the executable
add_executable(${PROJECT_NAME} tutorial4.cpp)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB2 glib-2.0 REQUIRED)
include_directories(${GLIB2_INCLUDE_DIRS})

# set path for libary
target_link_libraries(${PROJECT_NAME}
	${GLIB2_LIBRARIES}
)