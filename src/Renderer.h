//
// Created by Alex on 09/11/2018.
//

#ifndef DAC_RENDERER_H
#define DAC_RENDERER_H

#include <GLFW/glfw3.h>

class Renderer{
 public:
  bool *isTerminating;
  explicit Renderer(bool* isTerminating);
  int initalise();

 private:
  int instantiateWindow();
  int renderLoop();
  GLFWwindow *window;


};

#endif //DAC_RENDERER_H
