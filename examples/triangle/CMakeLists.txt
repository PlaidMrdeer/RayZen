cmake_minimum_required(VERSION 3.15)
project(triangle LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCE
        src/*.cpp
        src/*.h
)
add_executable(triangle ${SOURCE})

target_link_libraries(triangle PRIVATE RayZen)