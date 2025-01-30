cmake_minimum_required(VERSION 3.15)
project(RayZen VERSION 0.1.0 LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCE
        src/*.cpp
        src/*.c
        src/*.h
        include/*.h
)
add_library(RayZen SHARED ${SOURCE})
include_directories(include)
include_directories(src)

add_subdirectory(examples)

include(FetchContent)
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
)
FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 1.0.1
)
FetchContent_MakeAvailable(glfw glm)

find_package(OpenGL REQUIRED)
target_link_libraries(RayZen PUBLIC glfw glm::glm OpenGL)