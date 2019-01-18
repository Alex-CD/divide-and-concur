//
// Created by Alex on 26/11/2018.
//

#ifndef DAC_AUDIOHANDLER_H
#define DAC_AUDIOHANDLER_H

class AudioHandler{

 public:
  explicit AudioHandler(bool *isTerminating);
  static void *threadEntry(void *param);
  void start();

 private:
  bool *isTerminating;
  void audioLoop();
};

#endif //DAC_AUDIOHANDLER_H
