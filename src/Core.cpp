//
// Created by Alex
// Instantiates and stores the data used by the game's child threads.
//

#include <stdint.h>
#include <string>
#include <iostream>
#include <thread>
#include "Core.h"



/**
 * Default constructor
 */
Core::Core(){
  isTerminating = false;
  state = 0;
}

/**
 * Effectively the entry point for the core module.
 * Creates a new thread that initialises the other components.
 * Currently only initialises the rendering module.
 */
void Core::start(){
  DWORD threadID;
  unsigned int threadCount = 0;
  CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)initSelf, &threadCount, 0, &threadID);
  cout << "Message from core thread.";
}

/**
 * Internal method used as a target when creating a new thread.
 * CreateThread requires a static target to run, and this workaround allows us to
 * create a new thread on a nonstatic member.
 * Calling object is passed in lpParameter.
 * See the WINAPI createThread method additional info.
 *
 * @param lpParameter Data to pass to the new thread. Should contain a reference to the current object.
 * @return Unused.
 */
DWORD WINAPI Core::initSelf(LPVOID* lpParameter) {
  // Instantiate components
  Core *core = (Core*)lpParameter;
  core->initialise();
  return 0;
}

/**
 * Internal method, spawns child components for the game.
 * @return a status code indicating whether or not component creation was successful.
 */
int Core::initialise(){
  Renderer renderer;
  renderer.start();


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



