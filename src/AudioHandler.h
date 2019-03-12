//
// Created by Alex on 26/11/2018.
//

#ifndef DAC_AUDIOHANDLER_H
#define DAC_AUDIOHANDLER_H

#include "portaudio.h"
#include "AudioFile.h"
#include <string>
using namespace std;


class AudioHandler{

 public:
  explicit AudioHandler(bool *isTerminating, string sounds[], int soundsCount, string soundsDirectoryPath);
  static void *threadEntry(void *param);
  void start();
  int paStreamCallback(const void *input, void *output, unsigned long frameCount, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void *userData );
  void destroy();
 private:
  bool *isTerminating;
  void audioLoop();
  int soundsCount;
  AudioFile *sounds[];


};

#endif //DAC_AUDIOHANDLER_H
