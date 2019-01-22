//
// Created by alex on 21/01/19.
//

#include "SceneObject.h"

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

void SceneObject::setPos(float xPos, float yPos, float zPos) {
  this->xPos = xPos;
  this->yPos = yPos;
  this->zPos = zPos;
}

void SceneObject::translate(float xDistance, float yDistance, float zDistance) {
  this->xPos = this->xPos + xDistance;
  this->yPos = this->yPos + yDistance;
  this->zPos = this->zPos + zDistance;
}

void SceneObject::scale(float scaleFactor) {
  this->xTransform = this->xTransform * scaleFactor;
  this->yTransform = this->yTransform * scaleFactor;
  this->zTransform = this->zTransform * scaleFactor;
}

void SceneObject::setTransform(float xTransform, float yTransform, float zTransform) {
  this->xTransform = xTransform;
  this->yTransform = yTransform;
  this->zTransform = zTransform;
}

void SceneObject::transformByFactor(float xFactor, float yFactor, float zFactor) {
  this->xTransform = xTransform * xFactor;
  this->yTransform = yTransform * yFactor;
  this->zTransform = zTransform * zFactor;
}