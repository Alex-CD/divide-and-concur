cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(DAC CXX)



link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib )


add_executable(dac src/Main.cpp src/Core.cpp src/AudioHandler.cpp src/GameLogic.cpp src/Renderer.cpp src/InputHandler.cpp src/glad.c)
add_executable(dactest tests/Tests.cpp tests/CoreTests.cpp tests/RendererTests.cpp tests/GameLogicTests.cpp  tests/MainTests.cpp src/glad.c)

include_directories(include/)

include_directories(src/)


target_link_libraries(dac glfw3 opengl32)
target_link_libraries(dactest glfw3 opengl32)