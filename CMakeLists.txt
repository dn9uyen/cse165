cmake_minimum_required(VERSION 3.19.2 ) # first version to support apple silicon

project(cseProject)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(app src/main.cpp)

set(glbinding_DIR lib/glbinding)

find_package(glbinding REQUIRED)
find_package(glfw3 3.3.8 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(app
    glbinding::glbinding
    glfw
    OpenGL::GL
)

target_compile_options(app PRIVATE -Wall -Wextra -Wpedantic)
