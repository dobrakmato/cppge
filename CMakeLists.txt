cmake_minimum_required(VERSION 3.10)
project(cppge)

include_directories("glfw/include")
include_directories("glew/include")

set(ENKITS_BUILD_EXAMPLES OFF CACHE BOOL "Build basic example applications")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_INSTALL OFF CACHE BOOL "GLFW lib only")

add_subdirectory(thirdparty/glfw)
add_subdirectory(thirdparty/glew/build/cmake)

find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 11)

add_executable(cppge main.cpp)

target_link_libraries(cppge ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} glew_s glfw)