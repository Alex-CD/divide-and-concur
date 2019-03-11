//
// Created by alex on 22/02/19.
//

#include "ScreenObject.h"


ScreenObject::ScreenObject(int xPos, int yPos, int xSize, int ySize, string id):Object(id){
  this->xPos = xPos;
  this->yPos = yPos;
  this->xSize = xSize;
  this->ySize = ySize;
}

void ScreenObject::generateVertices(float *buffer, int xViewportSize, int yViewportSize) {

}

void ScreenObject::setPos(float xPos, float yPos, float zPos){}
void ScreenObject::translate(float xDistance, float yDistance, float zDistance){}
void ScreenObject::setTransform(float xTransform, float yTransform, float zTransform){}
void ScreenObject::transform(float xFactor, float yFactor, float zFactor){}
void ScreenObject::scale(float scaleFactor){}
void ScreenObject::scale(float xScale, float yScale, float zScale){}


