//
// Created by Alex on 23/11/2018.
//

#include "GameLogic.h"
#include "renderables/DoubleLinkedObject.h"


GameLogic::GameLogic(bool *isTerminating, DoubleLinkedObject* objects){
  this->isTerminating = isTerminating;
  this->objects = objects;
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



void GameLogic::logicLoop() {
  while(!isTerminating){
    //TODO game logic
  }
}