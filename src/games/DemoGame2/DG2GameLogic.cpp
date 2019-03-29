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
    if(this->mouse->leftButtonIsDown) {
      currentObject = objects->addObject(new Vector(Vec3(100.0f, 100.0f, 100.0f), ""));
      ((Vector *) currentObject)->setColour(Vec3(1.0f, 1.0f, 1.0f), Vec3(1.0f, 1.0f, 1.0f), Vec3(1.0f, 1.0f, 1.0f));
      currentObject->setPos(this->mouse->xPos, this->mouse->yPos, 0);

      clock_t clicktime = clock();

      int TICKS_COEF = 80000;

      while(this->mouse->leftButtonIsDown) {

        double scale = 1 + ((clock() - clicktime)/(TICKS_COEF)*0.05);
        currentObject->setTransform(scale, scale, 0);
        ((Vector *)currentObject)->setColour(Vec3(1.0f,scale*0.1f,scale*0.01f),Vec3(1.0f, 0.5f, 1.0f),Vec3(0.0f,scale*1.0f,scale*1.0f));
        currentObject->setPos(Vec3(this->mouse->xPos, this->mouse->yPos, 0));
      }
    }
    else if(this->mouse->middleButtonIsDown){
      currentObject = objects->addObject(new Vector(Vec3(100.0f, 100.0f, 100.0f), ""));
      ((Vector *)currentObject)->setColour(Vec3(0.5f, 0.0f, 0.0f),Vec3(1.0f, 0.5f, 1.0f),Vec3());
      currentObject->setPos(Vec3(this->mouse->xPos, this->mouse->yPos, 0));
    }

    if(this->mouse->rightButtonIsDown){
      this->saveLog("Hello world! This is a log. Gonna terminate now, if you don't mind.", "Game1");
      *this->isTerminating = true;
    }
  }


}

