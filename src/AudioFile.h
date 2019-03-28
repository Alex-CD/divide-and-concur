//
// Created by alex on 12/03/19.
//

#ifndef DAC_AUDIOFILE_H
#define DAC_AUDIOFILE_H

#include <string>

using namespace std;

/**
 * Audio files.
 * Used to store audio files to be played in games.
 */
class AudioFile {
 public:
  explicit AudioFile(int id, string filePath, int buffSize);
  void destroy();
  short *buff;
  int sampleRate;
  int channels;
  int id;
 private:
  string fileName;

 private:
};

#endif //DAC_AUDIOFILE_H
