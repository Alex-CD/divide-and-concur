//
// Created by alex on 13/02/19.
//


#ifndef DAC_FILEHELPER_H

#define DAC_FILEHELPER_H


#include <stdint.h>
#include <string>

using namespace std;


class FileHelper {
 public:
  static void saveString(string toSave, string filePath);
  static string loadString(string filePath);
};

#endif //DAC_FILEHELPER_H
