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
  auto *game = new DG3Core();
  auto *gamesThread = new pthread_t();
  int gamesCount = 0;
  bool keepGoing = true;

  pthread_create(gamesThread, nullptr, Core::threadEntry, game);


  /*auto *game2 = new DG2Core();
  auto *gamesThread2 = new pthread_t();

  pthread_create(gamesThread2, nullptr, Core::threadEntry, game2);
  cout << "\nPress enter to launch another game\n";
  */

  //do nothing
  while(true){}
}


