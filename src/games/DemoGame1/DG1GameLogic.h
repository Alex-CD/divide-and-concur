//
// Created by alex on 27/03/19.
//

#ifndef DAC_DG1GAMELOGIC_H
#define DAC_DG1GAMELOGIC_H

#include "GameLogic.h"

class DG1GameLogic:public GameLogic {

 public:
  explicit DG1GameLogic(bool *isTerminating, DoubleLinkedObject *objects, Mouse *mouse);
  void logicLoop();
 private:

};

#endif //DAC_DG1GAMELOGIC_H
