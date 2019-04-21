cmake_minimum_required(VERSION 2.8)

project(tender)
set (CMAKE_C_COMPILER "/usr/bin/gcc")
set (CMAKE_CXX_FLAGS "-std=c++14 -Wall")

# Gather sources in the directory
aux_source_directory (. SRC_LIST)
add_executable (${PROJECT_NAME} ${SRC_LIST})
