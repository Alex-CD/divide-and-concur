//
// Created by Alex on 07/11/2018.
//

#ifndef DAC_CORE_H
#define DAC_CORE_H

#include <thread>
#include <stdint.h>
#include <string>
#include <iostream>
#include <thread>
#include <core.h>



class core {

  bool isTerminated;
  thread renderer;
  thread game


  core(){
    isTerminated = false;
    thread renderer

    initialise();
  }

  int initialise(){
    /* create new threads
     * then terminate method */


    return -1;
  }

};

#endif //DAC_CORE_H
