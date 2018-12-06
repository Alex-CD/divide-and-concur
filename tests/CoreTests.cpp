//
// Created by Alex on 07/11/2018.
//
#include "catch.hpp"
#include "../src/Core.h"


TEST_CASE("Instantiating core"){
  Core core;
  core.start();
  //Should not raise exception!
}

TEST_CASE("Checking all components have initialised"){
  Core core;
  core.start();
  REQUIRE(core.getState() == 3);
}

TEST_CASE("Checking core can terminate"){
  Core core;
  core.start();
  int oldState =  core.getState();
  core.terminate();
  REQUIRE((oldState - core.getState()) == 0);
}
