cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(DAC CXX)


add_executable(dac src/Main.cpp src/Core.cpp src/Renderer.cpp src/InputHandler.cpp src/AudioHandler.cpp src/GameLogic.cpp src/Object.cpp src/Object.h src/renderables/Button.cpp src/renderables/Button.h src/renderables/Bitmap.cpp src/renderables/Bitmap.h src/renderables/None.cpp src/renderables/None.h src/renderables/ScreenObject.cpp src/renderables/ScreenObject.h src/renderables/GameWorldObject.cpp src/renderables/GameWorldObject.h src/renderables/InvisibleObject.cpp src/renderables/InvisibleObject.h src/renderables/Cursor.cpp src/renderables/Cursor.h src/renderables/Text.cpp src/renderables/Text.h src/renderables/Vector.cpp src/renderables/Vector.h src/FileHelper.cpp src/FileHelper.h)
add_executable(dactest tests/Tests.cpp tests/CoreTests.cpp tests/RendererTests.cpp tests/GameLogicTests.cpp src/Core.cpp src/Renderer.cpp src/InputHandler.cpp src/AudioHandler.cpp src/GameLogic.cpp src/FileHelper.cpp tests/AudioHandlerTests.cpp tests/FileHelperTests.cpp tests/FileHelperTests.cpp)

include_directories(include/)
include_directories(src/)


configure_file(src/shaders/FragmentShader.fsh shaders/FragmentShader.fsh COPYONLY)
configure_file(src/shaders/VertexShader.vsh shaders/VertexShader.vsh COPYONLY)
configure_file(tests/TestFile.txt test/TestFile.txt COPYONLY)


target_link_libraries(dac GL GLU glfw3 X11 Xxf86vm Xrandr pthread Xi dl Xcursor Xinerama)
target_link_libraries(dactest GL GLU glfw3 X11 Xxf86vm Xrandr pthread Xi dl Xcursor Xinerama)
