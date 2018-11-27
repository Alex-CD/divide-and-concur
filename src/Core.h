//
// Created by Alex on 07/11/2018.
//

#ifndef DAC_CORE_H
#define DAC_CORE_H

#include <string>
#include <thread>

#include "Renderer.h"
#include "AudioHandler.h"
#include "GameLogicTests.h"
#include "InputHandler.h"
using namespace std;



class Core{
 private:
  bool isTerminating;
  int state;
  Renderer renderer;
  GameLogic gameLogic;
  AudioHandler audioHandler;

 public:
  Core();
  int initialise();
  void terminate();
  int getState();
};

#endif //DAC_CORE_H
