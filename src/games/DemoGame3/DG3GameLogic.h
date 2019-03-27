//
// Created by alex on 19/02/19.
//

#ifndef DAC_CHESSCORE_H
#define DAC_CHESSCORE_H

#include <GameLogic.h>

class DG3GameLogic: public GameLogic {
 public:
  explicit DG3GameLogic(bool *isTerminating, DoubleLinkedObject *objects, Mouse *mouse);
  void logicLoop();
 private:
};

#endif //DAC_CHESSCORE_H
