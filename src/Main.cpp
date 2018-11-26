//
// Created by Alex on 18/10/2018.
//

#include <stdint.h>
#include <string>
#include <iostream>
#include <thread>
#include <Core.h>

using namespace std;

int main() {
  cout << "Welcome to divide and concur, a concurrency-based gamelogic environment for the modern era.";
  cout << "Please select a gamelogic to play";

  int max_games = 10;
  int current_games = 0;
  string keepPlaying;

  thread games[max_games];


  while(keepPlaying == "y"){

    if(current_games <= max_games){
      games[current_games + 1] = thread();
    }

    cin >> keepPlaying;
  }

}