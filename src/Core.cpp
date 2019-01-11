//
// Created by Alex
// Instantiates and stores the data used by the game's child threads.
//

#include <stdint.h>
#include <string>
#include <iostream>
#include "Core.h"
#include <pthread.h>



/**
 * Default constructor
 */
Core::Core(){
  isTerminating = false;
  state = 0;
}



/**
 * Internal method, spawns child components for the game.
 * @return a status code indicating whether or not component creation was successful.
 */
int Core::initialise(){
  Renderer renderer;

  return 0;
}

/**
 * Gets the current state of the child components.
 * @return A status code. 0=not launched, <0=error state, >0=nominal state.
 */
int Core::getState(){
  return state;
}


/**
 * Sends a terminate signal to the child threads.
 * CANNOT BE RELIED ON TO TERMINATE A STUCK LOGIC THREAD
 */
void Core::terminate() {
  isTerminating = true;
}



