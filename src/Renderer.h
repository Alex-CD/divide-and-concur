//
// Created by Alex on 09/11/2018.
//



#ifndef DAC_RENDERER_H
#define DAC_RENDERER_H

#include <GLFW/glfw3.h>
#include <thread>

using namespace std;

class Renderer{
 public:
  Renderer() = default;
  explicit Renderer(bool* isTerminating);
  int initalise();

 private:
  thread renderThread;
  int instantiateWindow();
  int renderLoop();
  GLFWwindow *window;
  bool *isTerminating;


};

#endif //DAC_RENDERER_H
