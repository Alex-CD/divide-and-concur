//
// Created by alex on 19/02/19.
//

#include "TestGameLogic.h"

#include "renderables/None.h"
#include "renderables/Vector.h"
#include "renderables/TexturedShape.h"

TestGameLogic::TestGameLogic(bool *isTerminating, DoubleLinkedObject *objects):GameLogic(isTerminating, objects) {
  this->objects->insertAfter(new DoubleLinkedObject(new Vector(0.5f, 0.5f, 0.5f, "texturedshape")));
}

void TestGameLogic::logicLoop(){
  while(!*this->isTerminating){
    //TODO
  }
}