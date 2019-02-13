#include "catch.hpp"
//
// Created by alex on 13/02/19.
//

#include "FileHelper.h"

using namespace std;


TEST_CASE("Loading text file", "[Smoke]"){
  string loadedText = FileHelper::loadString("TestFile.txt");

  string testText = "Non officia consequatur voluptatem dolorum aut.\n"
                    "Ut est quis eum fugiat qui explicabo rerum pariatur.\n"
                    "Non voluptatem sit debitis. Rerum est voluptatem possimus odit ullam laudantium ab.\n"
                    "Animi placeat est est et deserunt.\n";

  REQUIRE( testText == loadedText);
}

TEST_CASE("Saving text file", "[Smoke]"){

  string testText = "Non officia consequatur voluptatem dolorum aut.\n"
                    "Ut est quis eum fugiat qui explicabo rerum pariatur.\n"
                    "Non voluptatem sit debitis. Rerum est voluptatem possimus odit ullam laudantium ab.\n"
                    "Animi placeat est est et deserunt.\n";


  FileHelper::saveString("WrittenFile.txt", testText);

  REQUIRE( FileHelper::loadString("WrittenFile.txt") == testText );
}