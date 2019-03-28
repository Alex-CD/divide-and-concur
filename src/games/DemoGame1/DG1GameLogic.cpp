//
// Created by alex on 27/03/19.
//

#include <renderables/DoubleLinkedObject.h>
#include <Mouse.h>
#include <renderables/Vector.h>
#include "DG1GameLogic.h"
#include "GameLogic.h"

#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <stdint.h>



DG1GameLogic::DG1GameLogic(bool *isTerminating, DoubleLinkedObject *objects, Mouse *mouse):GameLogic(isTerminating, objects, mouse) {}

void DG1GameLogic::logicLoop(){

  bool buttonStillDown = false;
  Object *currentObj;

  srand(clock());

  clock_t lastObjCreation = clock();
  double intervalTicks = 2 * CLOCKS_PER_SEC;


  while(!*this->isTerminating){
    if((clock() - lastObjCreation) >= intervalTicks){
      currentObj = objects->addObject(this->objects->addObject(new Vector(Vec3(100.0f, 100.0f, 100.0f), "")));
      //((Vector*)currentObj)->setColour(Vec3(1.0f, 1.0f, 1.0f),Vec3(1.0f, 1.0f, 1.0f), Vec3(1.0f, 1.0f, 1.0f));


      currentObj->setPos(Vec3((rand() % 1000) - 500, (rand() % 1000) - 500, 0));
      lastObjCreation = clock();
    }
  }
}
