add_library(util SHARED vec3.cpp ray.cpp)

target_include_directories(util 
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR})