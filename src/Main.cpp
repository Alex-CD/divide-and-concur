//
// Created by Alex on 18/10/2018.
//

#include <stdint.h>
#include <string>
#include <iostream>
#include <windows.h>
#include "Core.h"


using namespace std;

int main() {
  cout << "Welcome to divide and concur, a concurrency-based gamelogic environment for the modern era.";
  cout << "Please select a gamelogic to play";


  int max_games = 10;
  string keepPlaying;

  unsigned int myCounter = 0;
  Core core;
  core.start();

  while(true){}


}

