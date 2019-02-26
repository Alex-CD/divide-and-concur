//
// Created by alex on 22/02/19.
//

#include "ScreenObject.h"


ScreenObject::ScreenObject(float xPos, float yPos, float xSize, float ySize, string id):Object(id){
  this->xPos = xPos;
  this->yPos = yPos;
  this->xSize = xSize;
  this->ySize = ySize;
}

void ScreenObject::generateVertices(float *buffer) {

}

void ScreenObject::setPos(float xPos, float yPos, float zPos){}
void ScreenObject::translate(float xDistance, float yDistance, float zDistance){}
void ScreenObject::setTransform(float xTransform, float yTransform, float zTransform){}
void ScreenObject::transform(float xFactor, float yFactor, float zFactor){}
void ScreenObject::scale(float scaleFactor){}
void ScreenObject::scale(float xScale, float yScale, float zScale){}


