//
// Created by Alex on 07/11/2018.
//
#include <iostream>
#include <pthread.h>
#include <thread>

#include "catch.hpp"
#include "Core.h"


TEST_CASE("Instantiating core (on stack)", "[Smoke]"){
  Core core;
  REQUIRE(core.getState() == 0);
}

TEST_CASE("Instantiating core (on heap)", "[Smoke]"){
  Core *core = new Core();
  REQUIRE(core->getState() == 0);

  delete core;
}

TEST_CASE("Instantiating core in new thread", "[Smoke]"){
  Core *core = new Core();
  pthread_t testthread;
  pthread_create(&testthread, nullptr, Core::threadEntry, &core);

  REQUIRE(core->getState() != 0);
  delete core;
}


TEST_CASE("Instantiating game thread then terminating", "[Smoke]"){
  Core *core = new Core();

  pthread_t testthread;
  pthread_create(&testthread, nullptr, Core::threadEntry, &core);

  core->terminate();
  REQUIRE(core->getState() == 0);

  delete core;
}


TEST_CASE("Checking core can terminate"){
  Core core;
  core.start();
  int oldState =  core.getState();
  core.terminate();
  REQUIRE((oldState - core.getState()) == 0);
}
