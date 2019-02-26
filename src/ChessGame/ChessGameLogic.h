//
// Created by alex on 19/02/19.
//

#ifndef DAC_CHESSCORE_H
#define DAC_CHESSCORE_H

#include <GameLogic.h>

class ChessGameLogic: public GameLogic {
 public:
  explicit ChessGameLogic(bool *isTerminating, DoubleLinkedObject *objects);
 private:
};

#endif //DAC_CHESSCORE_H
