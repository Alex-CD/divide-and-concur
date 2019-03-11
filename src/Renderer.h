//
// Created by Alex on 09/11/2018.
//



#ifndef DAC_RENDERER_H
#define DAC_RENDERER_H

#include <pthread.h>
#include <GLFW/glfw3.h>

#include "renderables/DoubleLinkedObject.h"
#include "Mouse.h"

using namespace std;

class Renderer {
 public:
  explicit Renderer(bool *isTerminating, int *maxObjects, DoubleLinkedObject *objects, Mouse *mouse);
  static void *threadEntry(void *param);
  void start();
  void showCursor();
  void hideCursor();

 private:
  GLuint shaderProgram;
  string loadShader(string sourceFile);
  GLFWwindow *window;

  int initWindow();
  void initGL();
  void initShaders();
  void initBuffers(GLuint* VAO, GLuint* VBO);
  void renderLoop();
  void saveLog(char* toSave, string filename);
  bool *isTerminating;
  int *maxObjects;
  int xViewportSizePx, yViewportSizePx;
  Mouse *mouse;
  DoubleLinkedObject *objects;

};

#endif //DAC_RENDERER_H
