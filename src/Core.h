//
// Created by Alex on 07/11/2018.
//

#ifndef DAC_CORE_H
#define DAC_CORE_H

#include <string>
#include <mutex>
#include <pthread.h>

#include "Renderer.h"
#include "AudioHandler.h"
#include "GameLogic.h"

#include "renderables/Object.h"
#include "renderables/DoubleLinkedObject.h"


using namespace std;

/**
 * 'Core' of a game.
 *  Each game has one instance of a Core.
 *
 *  Instantiates each of the child components belonging to a game, stores values shared between components,
 *  and coordinates sharing information between components.
 *
 *  Create a new class that inherits from this class (and naother one that inherits from GameLogic), if you want to create a new game.
 *  @see src/games/ for examples.
 */
class Core {
 public:
  Core();
  void terminate();
  int getState();
  static void *threadEntry(void *param);
  void start();
  int maxObjects;
  Renderer *renderer;
  GameLogic *gameLogic;
  AudioHandler *audioHandler;
  DoubleLinkedObject* objectsHead;
  Mouse mouse;
  bool isTerminating;


 private:
  pthread_t renderThread;
  pthread_t gameLogicThread;
  pthread_t audioHandlerThread;
  void startComponents();
  void disposeComponents();
};


#endif //DAC_CORE_H
