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

int Core::initialise() {
  // Instantiate components
  renderer = Renderer(&isTerminating);

  // Initialise components
  state += renderer.initalise();

  return state;
}


int Core::getState(){
  return state;
}

void Core::terminate() {
  isTerminating = true;
}



