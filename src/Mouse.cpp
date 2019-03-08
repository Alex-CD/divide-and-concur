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
void Mouse::updateMouseState(){
  glfwGetCursorPos(this->window, &this->xPos, &this->yPos);

  this->leftButtonIsDown = (glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS);
  this->middleButtonIsDown = (glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS);
  this->rightButtonIsDown = (glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS);
}

void Mouse::setMouseWindow(GLFWwindow *window) {
  this->window = window;
}