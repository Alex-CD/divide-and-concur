//
// Created by alex on 08/03/19.
//

#ifndef DAC_MOUSESTATE_H
#define DAC_MOUSESTATE_H

#include <GLFW/glfw3.h>

/**
 * Mouse object, used to track the current state of the mouse.
 * i.e. Buttons state, cursor location.
 */
class Mouse {
 public:
  Mouse();
  GLFWwindow *window;
  int xPos, yPos;
  bool leftButtonIsDown, rightButtonIsDown, middleButtonIsDown;
  void updateMouseState(int *xViewBoxSize, int *yViewBoxSize);
  void setMouseWindow(GLFWwindow *window);
  int clickRelToCenter(int relativeToTopLeft, int axisSize);
};


#endif //DAC_MOUSESTATE_H
