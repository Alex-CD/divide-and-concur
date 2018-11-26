//
// Created by Alex on 07/11/2018.
//

#ifndef DAC_CORE_H
#define DAC_CORE_H

#include <thread>
#include <string>
#include <thread>

using namespace std;


class Core{
 private:
  bool isTerminated;
  thread renderer;
  thread gameLogic;
  thread audioHandler;

 public:
  Core();
  int initialise();
};

#endif //DAC_CORE_H
