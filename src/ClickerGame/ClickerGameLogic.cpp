//
// Created by alex on 19/02/19.
//

#include <stdlib.h>
#include "time.h"

#include "ClickerGameLogic.h"
#include "renderables/Vector.h"

ClickerGameLogic::ClickerGameLogic(bool *isTerminating, DoubleLinkedObject *objects, Mouse *mouse):GameLogic(isTerminating, objects, mouse){

}

void ClickerGameLogic::logicLoop() {
  bool gameIsOver = false;
  bool mouseButtonHeld = false;

  srand((unsigned int)time(nullptr));

  int objectCount = 1;

  while(!*this->isTerminating){

    while(!gameIsOver){

      this->objects->addObject(new Vector(100, 100, 100, ""));


      //this->objects->lastObject->object->setTransform(0.0f, 0.0f, 0.f)
      // wait for next round to start

      while(!this->mouse->leftButtonIsDown && !mouseButtonHeld){

      }

      mouseButtonHeld = true;

    }

    while(!this->mouse->leftButtonIsDown){}
  }