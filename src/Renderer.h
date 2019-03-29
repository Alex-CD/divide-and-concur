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

/**
 * Renderer components.
 * Initialises an openGL context, and blindly renders the list of components it's given a pointer to.
 * A twitchy beast.
 * THIS SHOULDN'T BE EXTENDED IF YOU WANT A NEW GAME.
 * ONLY EXTEND GAME LOGIC AND CORE.
 */
class Renderer {
 public:
  explicit Renderer(bool *isTerminating, int *maxObjects, DoubleLinkedObject *objects, Mouse *mouse, string windowName);
  static void *threadEntry(void *param);
  void start();
  void showCursor();
  void hideCursor();
  static void initGL();

 private:
  GLuint shaderProgram;
  string loadShader(string sourceFile);
  GLFWwindow *window;
  int initWindow();
  void initShaders();
  void initBuffers(GLuint* VAO, GLuint* VBO);
  void renderLoop();
  void saveLog(char* toSave, string filename);
  bool *isTerminating;
  string windowText;
  int *maxObjects;
  int xViewportSizePx, yViewportSizePx;
  Mouse *mouse;
  DoubleLinkedObject *objects;

};

#endif //DAC_RENDERER_H
