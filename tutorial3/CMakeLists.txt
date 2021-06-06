# reference : https://github.com/jacking75/examples_CMake/blob/master/find_package_And_pkg_check_modules.md
cmake_minimum_required(VERSION 3.10)

# set the project name
project(tutorial3 CXX) 	# PROJECT_NAME is tutorial3

# set makefile verbose enable
SET(CMAKE_VERBOSE_MAKEFILE ON)

# add the executable
add_executable(${PROJECT_NAME} tutorial3.cpp)

# cmake --help-module-list
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB2 glib-2.0 REQUIRED)
include_directories(${GLIB2_INCLUDE_DIRS})

# set path for libary
target_link_libraries(${PROJECT_NAME}
	${GLIB2_LIBRARIES}
)