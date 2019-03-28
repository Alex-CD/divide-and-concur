//
// Created by alex on 28/01/19.
//

#include "Vector.h"



/**
 * Constructor for the vector class.
 * @param size Size of the vector to be created.
 * @param id ID of the object to create.
 */
Vector::Vector(Vec3 size, string id):WorldObject(size, Vec3(), id){
  this->col1 = Vec3();
  this->col2 = Vec3();
  this->col3 = Vec3();
}

/**
 * Constructor for the vector class.
 * @param colour1 Colour of the top corner in RGB
 * @param colour2 Colour of the bottom left in RGB, range 0-1.0f.
 * @param colour3 Colour of the bottom right in RGB, range 0-1.0f.
 * @param pos Position of the object to create.
 * @param size Size of the object to create, in px.
 * @param id Id of the object to create.
 */
Vector::Vector(Vec3 colour1, Vec3 colour2, Vec3 colour3, Vec3 pos, Vec3 size, string id):WorldObject(size, pos, id){
  this->col1 = colour1;
  this->col2 = colour2;
  this->col3 = colour3;
}

/**
 * Constructor for the vector class
 * @param pos Position of the object to create.
 * @param size Size of the object to create, in px.
 * @param id Id of the object to create.
 */
Vector::Vector(Vec3 pos, Vec3 size, string id):WorldObject(size, pos, id) {
  this->bufferSize = 3 * sizeof(int);

  //Default white colour
  this->col1 = Vec3(1.0f, 1.0f, 1.0f);
  this->col2 = Vec3(1.0f, 1.0f, 1.0f);
  this->col3 = Vec3(1.0f, 1.0f, 1.0f);
}

/**
 * Generates the vertices used to render this object, storing them in the given buffer.
 * Projects objects onto the view using an orthonographic projection.
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

  buffer[9] = this->col2.x;
  buffer[10] = this->col2.y;
  buffer[11] = this->col2.z;

  buffer[12] = (this->pos.x*xCoef) + (xScreenSize/2);
  buffer[13] = (this->pos.y*yCoef) - (yScreenSize/2);
  buffer[14] = 0.0f;

  buffer[15] = this->col3.x;
  buffer[16] = this->col3.y;
  buffer[17] = this->col3.z;
}

/**
 * Sets the colour of this vector.
 * @param col1 RGB colour for one of the corners.
 * @param col2 RGB colour for one of the corners.
 * @param col3 RGB colour for one of the corners.
 */
void Vector::setColour(Vec3 col1, Vec3 col2, Vec3 col3) {
  this->col1 = col1;
  this->col2 = col2;
  this->col3 = col3;
}

/**
 * A basic click detection algorithm - delects whether a click on the given cood was made on top of this vector.
 * @param xClick Click coordinate on the X plane, relative to the center of the screen.
 * @param yClick Click coordinate on the Y plane, relative to the center of the screen.
 * @return a boolean indicating whether the given coordinates were a 'hit'.
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