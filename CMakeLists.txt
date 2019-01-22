cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(DAC CXX)



link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib )

add_executable(dac src/Main.cpp src/Core.cpp src/Renderer.cpp src/InputHandler.cpp src/AudioHandler.cpp src/GameLogic.cpp src/SceneObject.cpp src/SceneObject.h)
add_executable(dactest tests/Tests.cpp tests/CoreTests.cpp tests/RendererTests.cpp tests/GameLogicTests.cpp src/Core.cpp src/Renderer.cpp src/InputHandler.cpp src/AudioHandler.cpp src/GameLogic.cpp tests/AudioHandlerTests.cpp)

include_directories(include/)
include_directories(src/)

target_link_libraries(dac GL GLU glfw3 X11 Xxf86vm Xrandr pthread Xi dl Xcursor Xinerama)
target_link_libraries(dactest GL GLU glfw3 X11 Xxf86vm Xrandr pthread Xi dl Xcursor Xinerama)
