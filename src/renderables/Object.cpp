//
// Created by alex on 21/01/19.
//

#include "Object.h"

/**
 * 
 * @param xSize Diameter of the object in the x plane.
 * @param ySize Diameter of the object in the y plane.
 * @param zSize Diameter of the object in the z plane.
 */
SceneObject::SceneObject(float xSize, float ySize, float zSize){
  this->xPos = 0.f;
  this->yPos = 0.f;
  this->zPos = 0.f;

  this->xSize = xSize;
  this->ySize = ySize;
  this->zSize = zSize;

  this->xTransform = 0.f;
  this->yTransform = 0.f;
  this->zTransform = 0.f;
};

/**
 *
 * @param xPos
 * @param yPos
 * @param zPos
 */
void SceneObject::setPos(float xPos, float yPos, float zPos) {
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
void SceneObject::translate(float xDistance, float yDistance, float zDistance) {
  this->xPos += xDistance;
  this->yPos += yDistance;
  this->zPos += zDistance;
}

/**
 *
 * @param scaleFactor
 */
void SceneObject::scale(float scaleFactor) {
  this->xSize *= scaleFactor;
  this->ySize *= scaleFactor;
  this->zSize *= scaleFactor;
}

/**
 *
 * @param xTransform
 * @param yTransform
 * @param zTransform
 */
void SceneObject::setTransform(float xTransform, float yTransform, float zTransform) {
  this->xTransform = xTransform;
  this->yTransform = yTransform;
  this->zTransform = zTransform;
}

/**
 *
 * @param xFactor
 * @param yFactor
 * @param zFactor
 */
void SceneObject::transform(float xFactor, float yFactor, float zFactor) {
  this->xTransform *= xFactor;
  this->yTransform *= yFactor;
  this->zTransform *= zFactor;
}