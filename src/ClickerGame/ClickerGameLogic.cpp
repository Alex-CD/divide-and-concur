//
// Created by alex on 19/02/19.
//

#include <stdlib.h>
#include <ctime>
#include <stdint.h>

#include "ClickerGameLogic.h"
#include "renderables/Vector.h"

ClickerGameLogic::ClickerGameLogic(bool *isTerminating, DoubleLinkedObject *objects, Mouse *mouse):GameLogic(isTerminating, objects, mouse){

}

void ClickerGameLogic::logicLoop() {

  bool gameIsOver = false;
  bool mouseButtonStillDown = false;

  const float ROUND_TIME_REDUCTION_FACTOR = 0.6f;
  const int INITIAL_ROUND_TIME_SECONDS = 3;


  srand(clock());


  Vector *currentObj = (Vector *)this->objects->addObject(new Vector(100, 100, 100, ""));

  while(!*this->isTerminating) {
    int roundsCount = 0;
    while(!gameIsOver){
      double roundLengthTicks = INITIAL_ROUND_TIME_SECONDS * CLOCKS_PER_SEC;


      while(!this->mouse->leftButtonIsDown && !currentObj->basicCollisionDetect(this->mouse->xPos, this->mouse->yPos)){
      }

      //prep for round start
      gameIsOver = true;
      clock_t roundStartTime = clock();
      this->objects->nextObject->object->setTransform(1.0f, 1.0f, 1.0f);


      while((clock() - roundStartTime) < roundLengthTicks){

        if(this->mouse->leftButtonIsDown){
          if(!mouseButtonStillDown && currentObj->basicCollisionDetect(this->mouse->xPos, this->mouse->yPos)){
            //Object clicked!
            gameIsOver = false;
            roundsCount += 1;
            roundLengthTicks = roundLengthTicks * ROUND_TIME_REDUCTION_FACTOR;
            currentObj->setPos((rand() % 1000) - 500, (rand() % 1000) - 500, 0);
          }

          mouseButtonStillDown = true;

        }
        else {
          mouseButtonStillDown = false;
        }
      }
    }

    // Make screen white
    currentObj->setTransform(10000.0f, 100000.0f, 10.f);

    cout << "You survived " +  std::to_string(roundsCount) + "rounds";

    //Wait until user clicks
    while(!this->mouse->leftButtonIsDown){}
    gameIsOver = false;

  }
}