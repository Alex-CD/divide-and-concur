//
// Created by Alex on 09/11/2018.
//



#ifndef DAC_RENDERER_H
#define DAC_RENDERER_H

#include <thread>
#include "windows.h"

using namespace std;

class Renderer{
 public:
  Renderer() = default;
  explicit Renderer(bool* isTerminating);
  int initialise();
  void start();

 private:
  thread renderThread;
  int instantiateWindow();
  int renderLoop();
  bool *isTerminating;
  static DWORD WINAPI initSelf(LPVOID* lpParameter);
};

#endif //DAC_RENDERER_H
