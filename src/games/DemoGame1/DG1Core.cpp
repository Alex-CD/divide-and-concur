//
// Created by alex on 27/03/19.
//

#include "DG1Core.h"
#include "DG1GameLogic.h"

// Initial window title should be set through the constructor for the core base class
DG1Core::DG1Core():Core("Demo Game 1 - \"Lots 'o Shapes\""){

  //Instantiate gamelogic component
  this->gameLogic = new DG1GameLogic(&isTerminating, this->objectsHead, &this->mouse);


  //Thread for this will be automatically created when this constructor finishes


  /*
  string audioFiles[] = {
      "pop.wav"
  };

  this->audioHandler = new AudioHandler(&isTerminating, audioFiles, 1, "DemoGame1/sounds/");
  */

}