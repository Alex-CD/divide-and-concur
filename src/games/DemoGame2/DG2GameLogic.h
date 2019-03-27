//
// Created by alex on 19/02/19.
//

#ifndef DAC_TESTGAMELOGIC_H
#define DAC_TESTGAMELOGIC_H

#include <GameLogic.h>
class DG2GameLogic: public GameLogic {
 public:
  void logicLoop(); // override
  DG2GameLogic(bool* isTerminating, DoubleLinkedObject *objects, Mouse *mouse);
 private:
};

#endif //DAC_TESTGAMELOGIC_H
