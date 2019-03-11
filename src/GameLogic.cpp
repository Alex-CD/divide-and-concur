//
// Created by Alex on 23/11/2018.
//

#include "GameLogic.h"
#include "renderables/DoubleLinkedObject.h"


GameLogic::GameLogic(bool *isTerminating, DoubleLinkedObject* objects, Mouse *mouse){
  this->isTerminating = isTerminating;
  this->objects = objects;
  this->mouse = mouse;
}


void* GameLogic::threadEntry(void *param) {
  auto *thisGameLogic = (GameLogic*)param;

  thisGameLogic->start();
  return nullptr;
}


void GameLogic::start() {
  //TODO initialise gamelogic component

  this->logicLoop();
}