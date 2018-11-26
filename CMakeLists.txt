cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(DAC)

include_directories(src)
include_directories(include)
include_directories(tests)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib )

add_executable(dac src/Main.cpp src/glad.c)


target_link_libraries(dac glfw3 opengl32)

