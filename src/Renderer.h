//
// Created by Alex on 09/11/2018.
//



#ifndef DAC_RENDERER_H
#define DAC_RENDERER_H

#include <thread>

using namespace std;

class Renderer{
 public:
  Renderer() = default;
  explicit Renderer(bool* isTerminating);
  static void *threadEntry(void *param);

 private:
  thread renderThread;
  int instantiateWindow();
  void renderLoop();
  bool *isTerminating;
  void start();
};

#endif //DAC_RENDERER_H
