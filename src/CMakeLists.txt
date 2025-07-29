cmake_minimum_required(VERSION 3.31.6)
project(rayutils)
add_library(rayutils
    vec3.cpp
    ray.cpp
    camera.cpp
    interval.cpp
)

target_include_directories(rayutils
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include) 