//
// Created by Alex
// Instantiates and stores the data used by the game's child threads.
//

#include <stdint.h>
#include <string>
#include <iostream>
#include <pthread.h>

#include "Core.h"


/**
 * Default constructor
 */
Core::Core(){
  this->isTerminating = false;
  this->state = 0;
  this->renderer = Renderer();
}

/**
 * Internal method, target of new thread creation
 */
void *Core::threadEntry(void *param){
  auto *thisGame = (Core*)param;
  thisGame->start();
  return nullptr;
}

void Core::start(){
  startComponents();
}


void Core::startComponents(){
  pthread_create(&this->renderThread, nullptr, Renderer::threadEntry, &this->renderer);
}

/**
 * Gets the current state of the child components.
 * @return A status code. 0=not launched, <0=error state, >0=nominal state.
 */
int Core::getState(){
  return state;
}

/**
 * Sends a terminate signal to the child threads.
 * CANNOT BE RELIED ON TO TERMINATE A STUCK LOGIC THREAD
 */
void Core::terminate() {
  this->isTerminating = true;
}



