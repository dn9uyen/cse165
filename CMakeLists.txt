cmake_minimum_required(VERSION 3.19.2 ) # first version to support apple silicon

project(cse165Project)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE INCLUDE include/*.h)
file(GLOB_RECURSE SOURCE src/*.cpp)

add_executable(PeggleClone ${INCLUDE} ${SOURCE})

find_package(OpenGL REQUIRED)
find_package(Qt6 PATHS lib/Qt-6.6.0 REQUIRED COMPONENTS Core Gui OpenGL OpenGLWidgets Widgets)

target_link_libraries(PeggleClone
    OpenGL::GL
    Qt6::Core
    Qt6::Gui
    Qt6::OpenGL
    Qt6::OpenGLWidgets
    Qt6::Widgets
)

target_compile_options(PeggleClone PRIVATE -Wall -Wextra -Wpedantic)
