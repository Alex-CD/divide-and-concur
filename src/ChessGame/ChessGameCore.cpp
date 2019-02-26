//
// Created by alex on 19/02/19.
//

#include "ChessGameCore.h"

#include <FileHelper.h>
#include "ChessGameLogic.h"


ChessGameCore::ChessGameCore():Core(){
  this->gameLogic = new ChessGameLogic(&isTerminating, this->objectsHead);
}