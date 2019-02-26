//
// Created by Alex on 23/11/2018.
//

#ifndef DAC_GAMELOGIC_H
#define DAC_GAMELOGIC_H

#include <renderables/DoubleLinkedObject.h>

class GameLogic {
 public:
  explicit GameLogic(bool *isTerminating, DoubleLinkedObject* objects);
  void start();
  static void *threadEntry(void *param);

 private:
  bool *isTerminating;
  void logicLoop();
  DoubleLinkedObject *objects;

};

#endif //DAC_GAMELOGIC_H
