//
// Created by alex on 27/03/19.
//

#include "DG1Core.h"
#include "DG1GameLogic.h"

DG1Core::DG1Core():Core(){
  this->gameLogic = new DG1GameLogic(&isTerminating, this->objectsHead, &this->mouse);

  // TODO load list from file
  string audioFiles[] = {
      "pop.wav"
  };

  this->audioHandler = new AudioHandler(&isTerminating, audioFiles, 1, "DemoGame2/sounds/");

}