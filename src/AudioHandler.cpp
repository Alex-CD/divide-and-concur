//
// Created by Alex on 26/11/2018.
//

#include "AudioHandler.h"

/**
 *
 * @param isTerminating
 */
AudioHandler::AudioHandler(bool *isTerminating) {
  this->isTerminating = isTerminating;
};

/**
 * Target for a new pthread on this component.
 * Redirects created thread to the start() thread in this component.
 * @param param Audiohandler on which new thread should run.
 * @return NA
 */
void* AudioHandler::threadEntry(void *param) {
  auto *thisAudioHandler = (AudioHandler*)param;
  thisAudioHandler->start();
  return nullptr;
}

/**
 * Entry point for the method.
 * If single thread, call this method.
 * If multithread, call threadEntry().
 */
void AudioHandler::start(){
  //TODO initialise audio output member
  audioLoop();
}

/**
 * Message loop, checks for sounds in the audio queue
 */
void AudioHandler::audioLoop() {
  while(!isTerminating){
    //play audio
  }
}

