//
// Created by alex on 19/02/19.
//

#include "TestGameLogic.h"

#include "renderables/None.h"
#include "renderables/Vector.h"
#include "renderables/TexturedShape.h"

TestGameLogic::TestGameLogic(bool *isTerminating, DoubleLinkedObject *objects):GameLogic(isTerminating, objects) {
  this->objects = new DoubleLinkedObject(new None());
  this->objects->insertAfter(new DoubleLinkedObject(new Vector(0.0f, 0.5f, 1.0f, "shape")));
  this->objects->nextObject->insertAfter(new DoubleLinkedObject(new TexturedShape(1.0f, 1.0f, 1.0f, "texturedshape")));
}

void TestGameLogic::logicLoop(){
  while(!*this->isTerminating){
    //TODO
  }
}