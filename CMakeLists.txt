cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(DAC CXX)



link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib )

add_executable(dac src/Main.cpp src/Core.cpp  src/Renderer.cpp src/GameLogic.cpp)
add_executable(dactest src/Core.cpp  src/Renderer.cpp tests/Tests.cpp tests/CoreTests.cpp tests/RendererTests.cpp tests/GameLogicTests.cpp  tests/MainTests.cpp src/glad.c)

include_directories(include/)
include_directories(src/)

target_link_libraries(dac GL GLU glfw3 X11 Xxf86vm Xrandr pthread Xi dl Xcursor Xinerama)
target_link_libraries(dactest GL GLU glfw3 X11 Xxf86vm Xrandr pthread Xi dl Xcursor Xinerama)
