//
// Created by alex on 13/02/19.
//

#include <stdint.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#include "FileHelper.h"



/**
 *
 * @return
 */
void FileHelper::saveString(string toSave, string filePath) {

  ofstream file(filePath);
  if (file.is_open())
  {
    file << toSave;
    file.close();
  }
}

/**
 *
 * @return
 */
string FileHelper::loadString(string filePath) {

  string line;
  string out;
  ifstream file(filePath);

  if(file.is_open())
  {
    while (getline(file,line))
    {
      out += (line + "\n");
    }

    file.close();
  }
  else
  {
    return "unable to read file!";
  }

  return out;
}