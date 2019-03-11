//
// Created by alex on 19/02/19.
//
#include "TestGameLogic.h"

#include "stdlib.h"
#include "time.h"

#include "renderables/None.h"
#include "renderables/Vector.h"
#include "renderables/TexturedShape.h"

TestGameLogic::TestGameLogic(bool *isTerminating, DoubleLinkedObject *objects, Mouse *mouse):GameLogic(isTerminating, objects, mouse) {
  this->objects->addObject(new Vector(50, 50, 0, "texturedshape"));
}

void TestGameLogic::logicLoop(){

  bool buttonStillDown = false;

  while(!*this->isTerminating){
    if(mouse->leftButtonIsDown && !buttonStillDown){
      buttonStillDown = true;


      this->objects->addObject(new Vector(0.0f, 0.0f, 0.0f, "texturedshape"));
      this->objects->nextObject->object->setPos(mouse->xPos, mouse->yPos, 0.0f);
    }

    if(!mouse->leftButtonIsDown ){
      buttonStillDown = false;
    }

  }
}