//
// Created by alex on 19/02/19.
//

#include "DG3Core.h"

#include <FileHelper.h>
#include "DG3GameLogic.h"


DG3Core::DG3Core():Core("Demo Game 3 - \"Clicker Game\""){
  this->gameLogic = new DG3GameLogic(&isTerminating, this->objectsHead, &this->mouse);
}