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
#include "GameLogic.h"
#include "InputHandler.h"


using namespace std;

class Core {
 public:
  Core();
  void terminate();
  int getState();
  static void *threadEntry(void *param);
  void start();
  int maxObjects;


 private:
  bool isTerminating;
  Renderer *renderer;
  GameLogic *gameLogic;
  AudioHandler *audioHandler;
  InputHandler *inputHandler;
  pthread_t renderThread;
  pthread_t gameLogicThread;
  pthread_t audioHandlerThread;
  //pthread_t inputHandlerThread;
  void startComponents();
  void disposeComponents();
};


#endif //DAC_CORE_H
