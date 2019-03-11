//
// Created by alex on 08/03/19.
//

#include "Mouse.h"

/**
 *
 */
Mouse::Mouse(){
  this->leftButtonIsDown = false;
  this->middleButtonIsDown = false;
  this->rightButtonIsDown = false;
  this->yPos = 0;
  this->xPos = 0;
  this->window = nullptr;
}


/**
 *
 */
void Mouse::updateMouseState(int *xViewBoxSize, int *yViewBoxSize){
  double xPosDouble, yPosDouble;

  glfwGetCursorPos(this->window, &xPosDouble, &yPosDouble);

  this->xPos = xPosDouble - (*xViewBoxSize / 2);
  this->yPos = (*yViewBoxSize / 2) - yPosDouble;

  this->leftButtonIsDown = (glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS);
  this->middleButtonIsDown = (glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS);
  this->rightButtonIsDown = (glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS);
}

void Mouse::setMouseWindow(GLFWwindow *window) {
  this->window = window;
}