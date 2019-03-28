//
// Created by alex on 28/01/19.
//

#include "Vector.h"


struct vec3 {
  float x;
  float y;
  float z;
};

/**
 *
 * @param xPos
 * @param yPos
 * @param zPos
 * @param id
 */
Vector::Vector(Vec3 colour1, Vec3 colour2, Vec3 colour3, Vec3 pos, Vec3 size, string id):WorldObject(pos, size, id){
  this->col1 = colour1;
  this->col2 = colour2;
  this->col3 = colour3;
}


Vector::Vector(Vec3 pos, Vec3 size, string id):WorldObject(pos, size, id) {
  this->bufferSize = 3 * sizeof(int);

  //Default white colour
  this->col1 = Vec3(1.0f, 1.0f, 1.0f);
  this->col2 = Vec3(1.0f, 1.0f, 1.0f);
  this->col3 = Vec3(1.0f, 1.0f, 1.0f);
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

  float xScreenSize = size.x * xCoef * transform.x;
  float yScreenSize = size.y* yCoef * transform.y;

  buffer[0] = (this->pos.x*xCoef) - (xScreenSize/2);
  buffer[1] = (this->pos.y*yCoef) - (yScreenSize/2);
  buffer[2] = 0.0f;

  buffer[3] = this->col1.x;
  buffer[4] = this->col1.y;
  buffer[5] = this->col1.z;

  buffer[6] = (this->pos.x*xCoef);
  buffer[7] = (this->pos.y*yCoef) + (yScreenSize/2);
  buffer[8] = 0.0f;

  buffer[3] = this->col2.x;
  buffer[4] = this->col2.y;
  buffer[5] = this->col2.z;

  buffer[12] = (this->pos.x*xCoef) + (xScreenSize/2);
  buffer[13] = (this->pos.y*yCoef) - (yScreenSize/2);
  buffer[14] = 0.0f;

  buffer[3] = this->col3.x;
  buffer[4] = this->col3.y;
  buffer[5] = this->col3.z;
}

/**
 * Detects whether or not this object has been clicked.
 * Treats the given object as a square.
 * @param xClick X-coordinate, (in pixels) of the given click (relative to the center)
 * @param yClick Y-coordinate, (in pixels) of the given click (relative to the center).
 * @return
 */
bool Vector::basicClickDetect(float xClick, float yClick){
  bool xHit;
  bool yHit;

  float objWidthX =  (this->size.x * this->transform.x)/2;
  float objWidthY = (this->size.y * this->transform.y)/2;

  xHit = (xClick > (this->pos.x - objWidthX)) && (xClick < (this->pos.x + objWidthX));
  yHit = (yClick > (this->pos.y - objWidthY)) && (yClick < (this->pos.y + objWidthY));

  return xHit && yHit;
}