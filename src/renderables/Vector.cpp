//
// Created by alex on 28/01/19.
//

#include "Vector.h"

Vector::Vector(float xPos, float yPos, float zPos, string id):WorldObject(xPos, yPos, zPos, id){
  this->bufferSize = 3 * sizeof(int);
}

void Vector::generateVertices(float *vertices, int xViewportSize, int yViewportSize) {
  float xCoef = 2.0f/xViewportSize;
  float yCoef = 2.0f/yViewportSize;

  float xScreenSize = xSize * xCoef * xTransform;
  float yScreenSize = ySize * yCoef * yTransform;

  //(this->xPos - (xSize/2);
  vertices[0] = (this->xPos*xCoef) - (xScreenSize/2);
  vertices[1] = (this->yPos*yCoef) - (yScreenSize/2);
  vertices[2] = 0.0f;

  vertices[3] = (this->xPos*xCoef);
  vertices[4] = (this->yPos*yCoef) + (yScreenSize/2);
  vertices[5] = 0.0f;

  vertices[6] = (this->xPos*xCoef) + (xScreenSize/2);
  vertices[7] = (this->yPos*yCoef) - (yScreenSize/2);
  vertices[8] = 0.0f;
}
