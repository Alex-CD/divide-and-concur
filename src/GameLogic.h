//
// Created by Alex on 23/11/2018.
//

#ifndef DAC_GAMELOGIC_H
#define DAC_GAMELOGIC_H

#include <renderables/DoubleLinkedObject.h>
#include "Mouse.h"

class GameLogic {
 public:
  explicit GameLogic(bool *isTerminating, DoubleLinkedObject* objects, Mouse *mouse);
  int clickRelToCenter(int relativeToTopLeft, int axisSize);
  void start();
  static void *threadEntry(void *param);
  DoubleLinkedObject *objects;
  bool *isTerminating;
  virtual void logicLoop() = 0;
  Mouse *mouse;
};

#endif //DAC_GAMELOGIC_H
