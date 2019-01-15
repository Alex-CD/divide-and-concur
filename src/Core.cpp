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
  this->renderer = new Renderer(&this->isTerminating);
}

/**
 * Create a new thread on this object for component multithreading.
 * Calls start() when run.
 */
void *Core::threadEntry(void *param){
  auto *thisGame = (Core*)param;
  thisGame->start();
  return nullptr;
}

/**
 * Does the logic of the Core module.
 * Can be called directly (for unit testing).
 * For multithreading, create new thread on threadEntry
 */
void Core::start(){
  startComponents();
}

/**
 * Internal method.
 * Creates new methods in each of the component threads,
 * and stores the thread pointers in the Core pthread_t members
 * (Components should already be initialised!)
 */
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



