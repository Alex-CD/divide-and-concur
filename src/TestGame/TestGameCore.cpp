//
// Created by alex on 19/02/19.
//

#include "TestGameCore.h"

#include "TestGameLogic.h"

TestGameCore::TestGameCore():Core(){
  this->gameLogic = new TestGameLogic(&isTerminating);
}