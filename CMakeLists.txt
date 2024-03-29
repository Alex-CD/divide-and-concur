cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(DAC CXX)


add_executable(dac src/Main.cpp src/Core.cpp src/Renderer.cpp src/AudioHandler.cpp src/GameLogic.cpp src/renderables/WorldObject.cpp src/renderables/WorldObject.h src/renderables/Button.cpp src/renderables/Button.h src/renderables/TexturedShape.cpp src/renderables/TexturedShape.h src/renderables/None.cpp src/renderables/None.h src/renderables/Sprite.cpp src/renderables/Sprite.h src/renderables/Text.cpp src/renderables/Text.h src/renderables/Vector.cpp src/renderables/Vector.h src/FileHelper.cpp src/FileHelper.h src/games/DemoGame3/DG3GameLogic.cpp src/games/DemoGame3/DG3GameLogic.h src/games/DemoGame2/DG2GameLogic.cpp src/games/DemoGame2/DG2GameLogic.h src/renderables/WorldObject.cpp src/renderables/WorldObject.h src/renderables/Object.cpp src/renderables/Object.h src/games/DemoGame3/DG3Core.cpp src/games/DemoGame3/DG3Core.h src/games/DemoGame2/DG2Core.cpp src/games/DemoGame2/DG2Core.h src/renderables/DoubleLinkedObject.cpp src/renderables/DoubleLinkedObject.h src/renderables/ScreenObject.cpp src/renderables/ScreenObject.h src/games/DemoGame2/DG2Core.cpp src/games/DemoGame2/DG2Core.h src/Mouse.cpp src/Mouse.h src/AudioFile.cpp src/AudioFile.h src/games/DemoGame1/DG1Core.cpp src/games/DemoGame1/DG1Core.h src/games/DemoGame1/DG1GameLogic.cpp src/games/DemoGame1/DG1GameLogic.h src/Vec3.cpp src/Vec3.h)
add_executable(dactest tests/Tests.cpp tests/CoreTests.cpp tests/RendererTests.cpp tests/GameLogicTests.cpp src/Core.cpp src/Renderer.cpp src/AudioHandler.cpp src/GameLogic.cpp src/FileHelper.cpp tests/AudioHandlerTests.cpp tests/FileHelperTests.cpp tests/FileHelperTests.cpp tests/DoubleLinkedObjectTests.cpp tests/DoubleLinkedObjectTests.h)

include_directories(include/)
include_directories(src/)


configure_file(src/shaders/FragmentShader.fsh shaders/FragmentShader.fsh COPYONLY)
configure_file(src/shaders/VertexShader.vsh shaders/VertexShader.vsh COPYONLY)
configure_file(tests/TestFile.txt test/TestFile.txt COPYONLY)


target_link_libraries(dac GL GLU glfw3 X11 Xxf86vm Xrandr pthread Xi dl Xcursor Xinerama portaudio sndfile)
target_link_libraries(dactest GL GLU glfw3 X11 Xxf86vm Xrandr pthread Xi dl Xcursor Xinerama portaudio sndfile)
