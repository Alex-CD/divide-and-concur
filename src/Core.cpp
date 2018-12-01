//
// Created by Alex on 07/11/2018.
//

#include <stdint.h>
#include <string>
#include <iostream>
#include <thread>
#include "Core.h"




Core::Core(){
  isTerminating = false;
  state = 0;
}

void Core::start(){
  DWORD threadID;
  unsigned int threadCount = 0;

  CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)initSelf, &threadCount, 0, &threadID);
}

DWORD WINAPI Core::initSelf(LPVOID* lpParameter) {
  // Instantiate components
  Core *core = (Core*)lpParameter;
  core->initialise();
  return 0;
}


int Core::initialise(){
  Renderer renderer;
  renderer.start();
  return 0;
}

int Core::getState(){
  return state;
}

void Core::terminate() {
  isTerminating = true;
}



