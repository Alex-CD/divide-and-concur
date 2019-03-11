//
// Created by alex on 21/01/19.
//

#include "WorldObject.h"

/**
 *
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
 *
 * @param xPos
 * @param yPos
 * @param zPos
 */
void WorldObject::setPos(int xPos, int yPos, int zPos) {
  this->xPos = xPos;
  this->yPos = yPos;
  this->zPos = zPos;
}

/**
 *
 * @param xDistance
 * @param yDistance
 * @param zDistance
 */
void WorldObject::translate(float xDistance, float yDistance, float zDistance) {
  this->xPos += xDistance;
  this->yPos += yDistance;
  this->zPos += zDistance;
}

/**
 *
 * @param scaleFactor
 */
void WorldObject::scale(float scaleFactor) {
  this->xTransform *= scaleFactor;
  this->xTransform *= scaleFactor;
  this->xTransform *= scaleFactor;
}

/**
 *
 * @param xTransform
 * @param yTransform
 * @param zTransform
 */
void WorldObject::setTransform(float xTransform, float yTransform, float zTransform) {
  this->xTransform = xTransform;
  this->yTransform = yTransform;
  this->zTransform = zTransform;
}

/**
 * @param xFactor
 * @param yFactor
 * @param zFactor
 */
void WorldObject::transform(float xFactor, float yFactor, float zFactor) {
  this->xTransform *= xFactor;
  this->yTransform *= yFactor;
  this->zTransform *= zFactor;
}

/**
 *
 * @param xScale
 * @param yScale
 * @param zScale
 */
void WorldObject::scale(float xScale, float yScale, float zScale){

}

void WorldObject::generateVertices(float *buffer) {
  // TODO
}