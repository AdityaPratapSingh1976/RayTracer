cmake_minimum_required(VERSION 3.31.6)
project(RayTracer VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
add_executable(RayTracer main.cpp vec3.cpp)