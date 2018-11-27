//
// Created by Alex on 18/10/2018.
//

#include <stdint.h>
#include <string>
#include <iostream>
#include <thread>
#include "Core.h"

using namespace std;

int main() {
  cout << "Welcome to divide and concur, a concurrency-based gamelogic environment for the modern era.";
  cout << "Please select a gamelogic to play";

  int max_games = 10;
  string keepPlaying;

  thread threads[max_games];
  Core* games[max_games];

  games[0] = new Core();
  threads[0] = thread( games[0]->initialise());

  while(keepPlaying == "y"){
    cin >> keepPlaying;
  }

}