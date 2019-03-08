//
// Created by alex on 19/02/19.
//

#ifndef DAC_TESTGAMELOGIC_H
#define DAC_TESTGAMELOGIC_H

#include <GameLogic.h>
class TestGameLogic: public GameLogic {
 public:
  void logicLoop(); // override
  TestGameLogic(bool* isTerminating, DoubleLinkedObject *objects, Mouse *mouse);
 private:
};

#endif //DAC_TESTGAMELOGIC_H
