//
// Created by Alex on 23/11/2018.
//

#ifndef DAC_GAMELOGIC_H
#define DAC_GAMELOGIC_H

class GameLogic {
 public:
  explicit GameLogic(bool *isTerminating);
  void start();
  static void *threadEntry(void *param);

 private:
  bool *isTerminating;
  void logicLoop();

};

#endif //DAC_GAMELOGIC_H
