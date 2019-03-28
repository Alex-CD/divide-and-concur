//
// Created by Alex
// Instantiates and stores the data used by the game's child threads.
//

#include <stdint.h>
#include <string>
#include <iostream>
#include <pthread.h>

#include "Core.h"
#include "renderables/None.h"
#include "Mouse.h"


/**
 * Default constructor
 */
Core::Core(){
  this->renderer = nullptr;
  this->audioHandler = nullptr;
  this->gameLogic = nullptr;
  this->isTerminating = false;
  this->maxObjects = 90000;
  this->mouse = Mouse();
  this->objectsHead = new DoubleLinkedObject(new None());

}


/**
 * Static method, to which new threads in an outer scope should be directed.
 * This directs threads onto a core object on which to run.
 * @param param The object on which this thread should run.
 */
void *Core::threadEntry(void *param){
  auto *thisGame = (Core*)param;
  thisGame->start();
  return nullptr;
}

/**
 * First method called by a new thread.
 * Do the high level stuff here!
 */
void Core::start(){
  startComponents();
  // do the next thing the core module needs to do
}

/**
 * Creates new methods in each of the component threads,
 * and stores the thread pointers in the Core pthread_t members
 * (Components should already be initialised!)
 */
void Core::startComponents(){
  this->renderer = new Renderer(&this->isTerminating, &this->maxObjects, this->objectsHead, &this->mouse);

  pthread_create(&this->renderThread, nullptr, Renderer::threadEntry, this->renderer);
  //pthread_create(&this->audioHandlerThread, nullptr, AudioHandler::threadEntry, this->audioHandler);
  pthread_create(&this->gameLogicThread, nullptr, GameLogic::threadEntry, this->gameLogic);
}

/**
 * Disposes of the components belonging to this core.
 */
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


