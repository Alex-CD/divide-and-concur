//
// Created by alex on 19/02/19.
//
#include "DG2GameLogic.h"

#include "stdlib.h"
#include <time.h>

#include "renderables/None.h"
#include "renderables/Vector.h"
#include "renderables/TexturedShape.h"

DG2GameLogic::DG2GameLogic(bool *isTerminating, DoubleLinkedObject *objects, Mouse *mouse):GameLogic(isTerminating, objects, mouse) {

}

void DG2GameLogic::logicLoop(){

  bool buttonStillDown = false;
  Object *currentObject;

  while(!*this->isTerminating){
    if(this->mouse->leftButtonIsDown){
      if(!buttonStillDown) {
        buttonStillDown = true;
        currentObject = objects->addObject(new Vector(100, 100, 100, ""));
        currentObject->setPos(this->mouse->xPos, this->mouse->yPos, 0);
      }
    }
    else {
      buttonStillDown = false;
    }
  }
  }

