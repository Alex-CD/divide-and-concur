//
// Created by alex on 12/03/19.
//

#include "AudioFile.h"

#include <sndfile.hh>


/**
 * Constructor for Audio file objects.
 * @param id Id of this audio file.
 * @param filePath Path to the audio file to load into this file.
 * @param buffSize Size of the buffer into which the file will be loaded.
 */
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

/**
 * Destroys the buffer of this object.
 * Call delete([thisobject]) to fully clean up.
 */
void AudioFile::destroy() {
  delete(this->buff);
}



