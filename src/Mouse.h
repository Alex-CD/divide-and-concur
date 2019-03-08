//
// Created by alex on 08/03/19.
//

#ifndef DAC_MOUSESTATE_H
#define DAC_MOUSESTATE_H

#include <GLFW/glfw3.h>

class Mouse {
 public:
  Mouse();
  GLFWwindow *window;
  double xPos, yPos;
  bool leftButtonIsDown, rightButtonIsDown, middleButtonIsDown;
  void updateMouseState();
  void setMouseWindow(GLFWwindow *window);
};


#endif //DAC_MOUSESTATE_H
