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
 * Saves a given string to a given file.
 * @param toSave String to save.
 * @param filePath File in which to save file (include file extension if needed)
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
 * Loads a given file to a string.
 * @param filePath Path to the file to load.
 * @return A string containing lines from the loaded file.
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