//
// Created by Alex on 23/11/2018.
//

#include <GameLogic.h>
#include <renderables/DoubleLinkedObject.h>
#include <FileHelper.h>


/**
 * Constructor for the gamelogic component.
 * @param isTerminating Pointer to the isTerminating value, which tracks if this components should gracefully exit.
 * @param objects Pointer to the linked list of renderable game objects accessible by this component.
 * @param mouse Pointer to the object representing the current state of the mouse.
 */
GameLogic::GameLogic(bool *isTerminating, DoubleLinkedObject* objects, Mouse *mouse){
  this->isTerminating = isTerminating;
  this->objects = objects;
  this->mouse = mouse;
}

/**
 * Saves a gameLog to a file.
 * @param logText Log text to save.
 * @param logName Name of the log (EXCLUDING EXTENSION)
 */
void GameLogic::saveLog(string logText, string logName) {
  FileHelper::saveString(logText, logName + ".gamelog");
}


/**
 * Static method, to which new threads in an outer scope should be directed.
 * This directs threads onto a core object on which to run.
 * @param The object on which this thread should run.
 */
void* GameLogic::threadEntry(void *param) {
  auto *thisGameLogic = (GameLogic*)param;

  thisGameLogic->start();
  return nullptr;
}


/**
 * First method run by new threads in this component.
 * Do the high level logic here!
 */
void GameLogic::start() {
  //TODO initialise gamelogic component

  this->logicLoop();
}