//
// Created by alex on 19/02/19.
//

#include "TestGameCore.h"

#include "TestGameLogic.h"

TestGameCore::TestGameCore():Core(){
  this->gameLogic = new TestGameLogic(&isTerminating, this->objectsHead, &this->mouse);

  // TODO load list from file
  string audioFiles[] = {
      "pop.wav"
  };

  this->audioHandler = new AudioHandler(&isTerminating, audioFiles, 1, "TestGame/sounds/");

}