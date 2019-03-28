//
// Created by Alex on 26/11/2018.
//

#include "AudioHandler.h"
#include "portaudio.h"

#include <string>
#include <sndfile.hh>

using namespace std;


/**
 *
 * @param isTerminating
 * @param sounds
 * @param soundsCount
 * @param soundsDirectoryPath
 */
AudioHandler::AudioHandler(bool *isTerminating, string sounds[], int soundsCount, string soundsDirectoryPath) {
  this->isTerminating = isTerminating;

  for(int i = 0; i < soundsCount; i++){
    this->sounds[i] = new AudioFile(i, soundsDirectoryPath + sounds[i], 10000);
  }

  int error = Pa_Initialize();



};

/**
 *
 * @param input
 * @param output
 * @param frameCount
 * @param timeInfo
 * @param statusFlags
 * @param userData
 * @return
 */
int AudioHandler::paStreamCallback(const void *input,
                                   void *output,
                                   unsigned long frameCount,
                                   const PaStreamCallbackTimeInfo *timeInfo,
                                   PaStreamCallbackFlags statusFlags,
                                   void *userData) {

}


/**
 *
 */
void AudioHandler::playFile() {

  //int error = Pa_OpenDefaultStream);

  /* Start the stream */
  //error = Pa_StartStream(stream);

  /* Run until EOF is reached */
  while(Pa_IsStreamActive(stream))
  {
    Pa_Sleep(100);
  }

  /* Close the soundfile */
  //sf_close(file);

}


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
void AudioHandler::start() {

}
/**
 * Message loop, checks for sounds in the audio queue
 */
void AudioHandler::audioLoop(){

}

void AudioHandler::destroy() {

  for(int i = 0; i < this->soundsCount; i++){
    sounds[i]->destroy();
    delete(sounds[i]);
  }
}

