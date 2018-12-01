//
// Created by Alex on 07/11/2018.
//

#ifndef DAC_CORE_H
#define DAC_CORE_H

#include <string>
#include <thread>
#include <mutex>

#include "Renderer.h"
#include "AudioHandler.h"
#include "GameLogicTests.h"
#include "InputHandler.h"
#include "windows.h"

using namespace std;

class Core {

 private:
  bool isTerminating;
  int state;
  Renderer renderer;
  GameLogic gameLogic;
  AudioHandler audioHandler;
  int initialise();
  static DWORD WINAPI initSelf(LPVOID* lpParameter);

 public:
  Core();
  static void start();
  void terminate();
  int getState();
};

#endif //DAC_CORE_H
