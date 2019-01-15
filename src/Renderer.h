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
  explicit Renderer(bool *isTerminating);
  static void *threadEntry(void *param);
  void start();

 private:
  GLFWwindow *window;
  int instantiateWindow();
  void renderLoop();
  bool *isTerminating;
};

#endif //DAC_RENDERER_H
