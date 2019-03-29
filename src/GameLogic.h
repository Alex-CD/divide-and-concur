//
// Created by Alex on 23/11/2018.
//

#ifndef DAC_GAMELOGIC_H
#define DAC_GAMELOGIC_H

#include <renderables/DoubleLinkedObject.h>
#include <FileHelper.h>
#include <Mouse.h>
#include <iostream>
#include <cmath>

/**
 * Contains the code on which the logic thread of an instantiation of a game runs.
 * Different for each different game.
 */
class GameLogic {
 public:
  explicit GameLogic(bool *isTerminating, DoubleLinkedObject* objects, Mouse *mouse);
  void start();
  static void *threadEntry(void *param);
  DoubleLinkedObject *objects;
  bool *isTerminating;
  virtual void logicLoop() = 0;
  void saveLog(string logText, string logName);
  Mouse *mouse;
};

#endif //DAC_GAMELOGIC_H
