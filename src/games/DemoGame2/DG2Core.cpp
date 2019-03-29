//
// Created by alex on 19/02/19.
//

#include "DG2Core.h"

#include "DG2GameLogic.h"

DG2Core::DG2Core():Core("Demo Game 2 - \"Click me baby, one more time\""){
  this->gameLogic = new DG2GameLogic(&isTerminating, this->objectsHead, &this->mouse);

  // TODO load list from file
  string audioFiles[] = {
      "pop.wav"
  };

  this->audioHandler = new AudioHandler(&isTerminating, audioFiles, 1, "DemoGame2/sounds/");

}