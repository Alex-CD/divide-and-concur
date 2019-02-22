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
  this->renderer = nullptr;
  this->audioHandler = nullptr;
  this->gameLogic = nullptr;
  this->isTerminating = false;
  this->maxObjects = 5;
  this->objectsHead = nullptr;
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

  // do the next thing the core module needs to do
}

/**
 * Internal method.
 * Creates new methods in each of the component threads,
 * and stores the thread pointers in the Core pthread_t members
 * (Components should already be initialised!)
 */
void Core::startComponents(){
  this->renderer = new Renderer(&this->isTerminating, &this->maxObjects);
  this->audioHandler = new AudioHandler(&this->isTerminating);
  this->gameLogic = new GameLogic(&this->isTerminating);

  pthread_create(&this->renderThread, nullptr, Renderer::threadEntry, this->renderer);
  pthread_create(&this->audioHandlerThread, nullptr, AudioHandler::threadEntry, this->audioHandler);
  pthread_create(&this->gameLogicThread, nullptr, GameLogic::threadEntry, this->gameLogic);
}

void Core::disposeComponents(){
  delete this->renderer;
  delete this->audioHandler;
  delete this->gameLogic;
}


/**
 * Indicates how many components are currently running.
 * (More precisely, how many are initialised.)
 * @return Running component count.
 */
int Core::getState(){
  return (this->renderer != nullptr)
      + (this->gameLogic != nullptr)
      + (this->audioHandler != nullptr);
}

/**
 * Sends a terminate signal to the child threads.
 * CANNOT BE RELIED ON TO TERMINATE A STUCK LOGIC THREAD
 */
void Core::terminate() {
  this->isTerminating = true;
}


