//
// Created by alex on 27/03/19.
//

#include <renderables/DoubleLinkedObject.h>
#include <Mouse.h>
#include <GameLogic.h>
#include <renderables/Vector.h>

#include <games/DemoGame1/DG1GameLogic.h>
#include <random>


DG1GameLogic::DG1GameLogic(bool *isTerminating, DoubleLinkedObject *objects, Mouse *mouse):GameLogic(isTerminating, objects, mouse) {}

// This thread should be nonterminating, containing a loop that terminates when this->isTerminating is true.
void DG1GameLogic::logicLoop(){

  bool buttonStillDown = false;
  Object *currentObj;

  std::random_device rd;
  std::mt19937_64 gen(rd());
  std::uniform_real_distribution<float> rgen(0.0f, 1.0f);


  // Generates random coef between 0.0 and 1
  //rgen(gen);


  clock_t lastObjCreation = clock();
  double intervalTicks = 0.1 * CLOCKS_PER_SEC;

  float OBJ_SIZE_RANGE = 200.0f;
  float MIN_OBJ_WIDTH = 50.0f;


  while(!*this->isTerminating){
    if((clock() - lastObjCreation) >= intervalTicks){


      Vec3 size = Vec3(OBJ_SIZE_RANGE*rgen(gen) + MIN_OBJ_WIDTH, OBJ_SIZE_RANGE*rgen(gen) + MIN_OBJ_WIDTH, 0);
      Vec3 col1 = Vec3(rgen(gen), rgen(gen), rgen(gen));
      Vec3 col2 = Vec3(rgen(gen), rgen(gen), rgen(gen));
      Vec3 col3 = Vec3(rgen(gen), rgen(gen), rgen(gen));

      currentObj = (Vector *)this->objects->addObject(new Vector(size, ""));
      ((Vector*)currentObj)->setColour(col1, col2, col3);
      currentObj->setPos((rgen(gen)*1920.0f) - 960.0f, (rgen(gen)*1080.0f) - 540, 0);

      if(mouse->leftButtonIsDown){
        objects->disposeOfList();
      }

      lastObjCreation = clock();

    }
  }
}
