cmake_minimum_required(VERSION 3.31.6)
project(raymath)
add_library(raymath vec3.cpp ray.cpp)

target_include_directories(raymath 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include)