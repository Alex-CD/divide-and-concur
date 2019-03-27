//
// Created by alex on 21/01/19.
//

#include "WorldObject.h"

/**
 * Constructor for WorldObjects
 * @param xSize Diameter of the object in the x plane.
 * @param ySize Diameter of the object in the y plane.
 * @param zSize Diameter of the object in the z plane.
 */
WorldObject::WorldObject(float xSize, float ySize, float zSize, string id):Object(id){
  this->xPos = 0.0f;
  this->yPos = 0.0f;
  this->zPos = 0.0f;

  this->xSize = xSize;
  this->ySize = ySize;
  this->zSize = zSize;

  this->xTransform = 1.0f;
  this->yTransform = 1.0f;
  this->zTransform = 1.0f;
};

/**
 * Sets the position of this world object, relative to the center of the window.
 * @param xPos X-coord of this object in Px
 * @param yPos Y-coord of this object in Px
 * @param zPos Z-coord of this object in Px
 */
void WorldObject::setPos(int xPos, int yPos, int zPos) {
  this->xPos = xPos;
  this->yPos = yPos;
  this->zPos = zPos;
}

/**
 * Moves this object a distance (in px)
 * @param xDistance Distance to move (in the x plane)
 * @param yDistance Distance to move. (in the y plane)
 * @param zDistance Distnace to move. (in the z plane)
 */
void WorldObject::translate(float xDistance, float yDistance, float zDistance) {
  this->xPos += xDistance;
  this->yPos += yDistance;
  this->zPos += zDistance;
}

/**
 * Scales the object by a factor (taking into account current scaling), preserving aspect ratio.
 * @param scaleFactor Factor to scale by.
 */
void WorldObject::scale(float scaleFactor) {
  this->xTransform *= scaleFactor;
  this->xTransform *= scaleFactor;
  this->xTransform *= scaleFactor;
}

/**
 *
 * @param scaleFactorX
 * @param scaleFactorY
 * @param scaleFactorZ
 */
void WorldObject::scale(float scaleFactorX,float scaleFactorY, float scaleFactorZ) {
  this->xTransform *= scaleFactorX;
  this->xTransform *= scaleFactorY;
  this->xTransform *= scaleFactorZ;
}

/**
 * Sets the scale factors of this object.
 * @param xTransform Factor to scale by, in the x plane.
 * @param yTransform Factor to scale by, in the y plane
 * @param zTransform Factor to scale by, in the z plane
 */
void WorldObject::setTransform(float xTransform, float yTransform, float zTransform) {
  this->xTransform = xTransform;
  this->yTransform = yTransform;
  this->zTransform = zTransform;
}

/**
 * Scales this object by the given scale factors (taking into account current scaling), without preserving aspect ratio.
 * @param xTransform Factor to scale by, in the x plane.
 * @param yTransform Factor to scale by, in the y plane
 * @param zTransform Factor to scale by, in the z plane
 */
void WorldObject::transform(float xFactor, float yFactor, float zFactor) {
  this->xTransform *= xFactor;
  this->yTransform *= yFactor;
  this->zTransform *= zFactor;
}

/**
 * Generates the vertices for this object,
 * outputs into the given buffer.
 * @param buffer Buffer to store vertices in.
 */
void WorldObject::generateVertices(float *buffer) {
  // TODO
}