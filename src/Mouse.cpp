//
// Created by alex on 08/03/19.
//

#include "Mouse.h"

/**
 * Default constructor for the mouse class.
 * Sets all values to default.
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
 * Updates the booleans indicating mouse button state.
 * Viewbox size is used to calculate location of click relative to the cneter of the screen.
 * @param xViewBoxSize Size of the viewbox in px, in the X plane.
 * @param yViewBoxSize Size of the viewbox in px, in the Y plane.
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

/**
 * Sets the GLFW context to which this mouse object is bound.
 * @param window
 */
void Mouse::setMouseWindow(GLFWwindow *window) {
  this->window = window;
}