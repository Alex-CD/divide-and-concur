#include <iostream>
#include <pthread.h>
#include <thread>

#include "catch.hpp"
#include "AudioHandler.h"



// There isn't really much I can test for at this stage
TEST_CASE("Instantiating ", "[smoke]"){

  bool isTerminating = false;
  AudioHandler audioHandler = AudioHandler(&isTerminating);
  audioHandler.start();
}
