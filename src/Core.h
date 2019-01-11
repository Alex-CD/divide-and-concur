//
// Created by Alex on 07/11/2018.
//

#ifndef DAC_CORE_H
#define DAC_CORE_H

#include <string>
#include <mutex>
#include <pthread.h>

#include "Renderer.h"
#include "AudioHandler.h"
#include "GameLogicTests.h"
#include "InputHandler.h"


using namespace std;

class Core {

 private:
  bool isTerminating;
  pthread_t coreThread;
  int state;
  Renderer renderer;
  GameLogic gameLogic;
  AudioHandler audioHandler;
  //InputHandler inputHandler;
  void start();



 public:
  Core();
  void terminate();
  int getState();
  static void *threadEntry(void *param);
};

#endif //DAC_CORE_H
