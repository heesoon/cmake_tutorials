cmake_minimum_required(VERSION 3.10)

# set the project name
project(tutorial3 CXX) 	# PROJECT_NAME is tutorial3

# set makefile verbose enable
SET(CMAKE_VERBOSE_MAKEFILE ON)

# add the executable
add_executable(${PROJECT_NAME} tutorial3.cpp)

# add_library for imported library
add_library(imported_glib2 SHARED IMPORTED)

# setting target property for imported library (glib-2.0)
set_target_properties(imported_glib2
	PROPERTIES IMPORTED_LOCATION
	/usr/lib/x86_64-linux-gnu/libglib-2.0.so
)

# setting glib-2.0 include path
include_directories(
	${CMAKE_SOURCE_DIR}/include
	/usr/include/glib-2.0
)

# set path for libary
target_link_libraries(${PROJECT_NAME}
	imported_glib2
)