//
// Created by alex on 19/02/19.
//

#include "ClickerGameCore.h"

#include <FileHelper.h>
#include "ClickerGameLogic.h"


ClickerGameCore::ClickerGameCore():Core(){
  this->gameLogic = new ClickerGameLogic(&isTerminating, this->objectsHead, &this->mouse);
}