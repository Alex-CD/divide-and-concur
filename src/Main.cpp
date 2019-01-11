//
// Created by Alex on 18/10/2018.
//

#include <stdint.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include "Core.h"

using namespace std;

/**
 * Launches the game.
 * @return Application exit code.
 */
int main() {
  const int MAX_THREADS = 15;


  cout << "Welcome to divide and concur, a concurrency-based gamelogic environment for the modern era.";
  auto *games = new Core[MAX_THREADS];
  auto *gamesThreads = new pthread_t[MAX_THREADS];
  int gamesCount = 0;
  bool keepGoing = true;


  while(gamesCount < MAX_THREADS && keepGoing){
    games[gamesCount].terminate();
    pthread_create(&gamesThreads[gamesCount], nullptr, Core::threadEntry, &games[gamesCount]);
    cout << "\nPress enter to launch another game\n";
    cin >> keepGoing;
    gamesCount += 1;
  }

  return 0;
}

