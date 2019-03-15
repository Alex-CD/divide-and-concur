//
// Created by alex on 28/01/19.
//

#include "Vector.h"

/**
 *
 * @param xPos
 * @param yPos
 * @param zPos
 * @param id
 */
Vector::Vector(float xPos, float yPos, float zPos, string id):WorldObject(xPos, yPos, zPos, id){
  this->bufferSize = 3 * sizeof(int);
}

/**
 * Generates the vertices used to render this object, storing them in the given buffer.
 * @param buffer The buffer in which to store the vertices.
 * @param xViewportSize Size of the viewport (in the X place)
 * @param yViewportSize Size of the viewport (in the Y plane)
 */
void Vector::generateVertices(float *buffer, int xViewportSize, int yViewportSize) {
  float xCoef = 2.0f/xViewportSize;
  float yCoef = 2.0f/yViewportSize;

  float xScreenSize = xSize * xCoef * xTransform;
  float yScreenSize = ySize * yCoef * yTransform;

  buffer[0] = (this->xPos*xCoef) - (xScreenSize/2);
  buffer[1] = (this->yPos*yCoef) - (yScreenSize/2);
  buffer[2] = 0.0f;

  buffer[3] = (this->xPos*xCoef);
  buffer[4] = (this->yPos*yCoef) + (yScreenSize/2);
  buffer[5] = 0.0f;

  buffer[6] = (this->xPos*xCoef) + (xScreenSize/2);
  buffer[7] = (this->yPos*yCoef) - (yScreenSize/2);
  buffer[8] = 0.0f;
}

/**
 * Detects whether or not this object has been clicked.
 * Treats the given object as a square.
 * @param xClick X-coordinate, (in pixels) of the given click (relative to the center)
 * @param yClick Y-coordinate, (in pixels) of the given click (relative to the center).
 * @return
 */
bool Vector::basicClickDetect(float xClick, float yClick) {
  bool xHit;
  bool yHit;

  float objWidthX =  (this->xSize * this->xTransform)/2;
  float objWidthY = (this->ySize * this->yTransform)/2;

  xHit = (xClick > (this->xPos - objWidthX)) && (xClick < (this->xPos + objWidthX));
  yHit = (yClick > (this->yPos - objWidthY)) && (yClick < (this->yPos + objWidthY));

  return xHit && yHit;
}