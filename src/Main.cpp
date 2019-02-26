//
// Created by Alex on 18/10/2018.
//

#include <stdint.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include "Core.h"

#include <ChessGame/ChessGameLogic.h>
#include <TestGame/TestGameLogic.h>
#include <TestGame/TestGameCore.h>

using namespace std;

/**
 * Launches the game.
 * @return Application exit code.
 */
int main() {
  const int MAX_THREADS = 15;

  cout << "Welcome to divide and concur, a concurrency-based gamelogic environment for the modern era.";
  auto *game = new TestGameCore();
  auto *gamesThread = new pthread_t();
  int gamesCount = 0;
  bool keepGoing = true;

  pthread_create(gamesThread, nullptr, Core::threadEntry, game);
  cout << "\nPress enter to launch another game\n";

  //do nothing
  while(true){}
}


