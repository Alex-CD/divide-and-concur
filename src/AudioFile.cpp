//
// Created by alex on 12/03/19.
//

#include "AudioFile.h"

#include <sndfile.hh>


AudioFile::AudioFile(int id, string filePath, int buffSize) {

  this->fileName = filePath;
  this->id = id;
  this->buff = new short[buffSize];

  // Reading audio file
  SndfileHandle file = SndfileHandle(filePath);

  file.read(this->buff, buffSize);

  this->sampleRate = file.samplerate();
  this->channels = file.channels();
}

void AudioFile::destroy() {
  delete(this->buff);
}



