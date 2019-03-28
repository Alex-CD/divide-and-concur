//
// Created by Alex on 18/10/2018.
//

#include <stdint.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include "Core.h"

#include <games/DemoGame1/DG1GameLogic.h>
#include <games/DemoGame1/DG1Core.h>

#include <games/DemoGame2/DG2GameLogic.h>
#include <games/DemoGame2/DG2Core.h>

#include <games/DemoGame3/DG3GameLogic.h>
#include <games/DemoGame3/DG3Core.h>

using namespace std;

/**
 * Launches the game.
 * @return Application exit code.
 */
int main() {
  const int MAX_THREADS = 15;

  cout << "Welcome to divide and concur, a concurrency-based gamelogic environment for the modern era.";
  auto *game1 = new DG1Core();
  auto *game1Thread = new pthread_t();

  Renderer::initGL();

  auto *game2 = new DG2Core();
  auto *game2Thread = new pthread_t();

  auto *game3 = new DG3Core();
  auto *game3Thread = new pthread_t();

  int gamesCount = 0;
  bool keepGoing = true;

  //pthread_create(game1Thread, nullptr, Core::threadEntry, game1);
  //pthread_create(game2Thread, nullptr, Core::threadEntry, game2);
  pthread_create(game3Thread, nullptr, Core::threadEntry, game3);

  //do nothing
  while(true){}

}


