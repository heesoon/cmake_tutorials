cmake_minimum_required(VERSION 3.10)

# set the project name
project(tutorial5 CXX)

# set makefile verbose enable
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 11)

include(ExternalProject)
ExternalProject_Add(GoogleTest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           master
  INSTALL_COMMAND   ""
)

ExternalProject_Get_Property(GoogleTest source_dir binary_dir)

message("hskim source_dir : " ${source_dir})

find_package(Threads REQUIRED)

file(GLOB SRCS ${PROJECT_SOURCE_DIR}/*.cpp)
add_executable(${PROJECT_NAME}
	${SRCS}
)

add_dependencies(${PROJECT_NAME}
	GoogleTest
)

include_directories(${source_dir}/include)

# set path for libary
target_link_libraries(${PROJECT_NAME}
	Threads::Threads
	${binary_dir}/libgtest.a
)