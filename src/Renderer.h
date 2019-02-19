//
// Created by Alex on 09/11/2018.
//



#ifndef DAC_RENDERER_H
#define DAC_RENDERER_H

#include <pthread.h>
#include <GLFW/glfw3.h>

using namespace std;

class Renderer {
 public:
  explicit Renderer(bool *isTerminating, int *maxObjects);
  static void *threadEntry(void *param);
  void start();
  void showCursor();
  void hideCursor();

 private:
  GLuint shaderProgram, vertexBuffer;
  string loadShader(string sourceFile);
  GLFWwindow *window;

  int initWindow();
  void initGL();
  void renderLoop();
  void saveLog(char* toSave, string filename);
  bool *isTerminating;
  int *maxObjects;
};

#endif //DAC_RENDERER_H
