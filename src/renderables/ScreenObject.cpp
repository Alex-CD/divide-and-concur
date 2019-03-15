//
// Created by alex on 22/02/19.
//

#include "ScreenObject.h"


/**
 * Constructor for the screenobject parent class.
 * @param xPos X-coord of the object, in pixels, relative to the center of the screen.
 * @param yPos Y-coord of the object, in pixels, relative to the center of the screen.
 * @param xSize Size of the object (in the X-plane) in pixels.
 * @param ySize Size of the object (in the Y-plane) in pixels.
 * @param id Id of this object.
 */
ScreenObject::ScreenObject(int xPos, int yPos, int xSize, int ySize, string id):Object(id){
  this->xPos = xPos;
  this->yPos = yPos;
  this->xSize = xSize;
  this->ySize = ySize;
}

// TODO
void ScreenObject::generateVertices(float *buffer, int xViewportSize, int yViewportSize) {}
void ScreenObject::setPos(float xPos, float yPos, float zPos){}
void ScreenObject::translate(float xDistance, float yDistance, float zDistance){}
void ScreenObject::setTransform(float xTransform, float yTransform, float zTransform){}
void ScreenObject::transform(float xFactor, float yFactor, float zFactor){}
void ScreenObject::scale(float scaleFactor){}
void ScreenObject::scale(float xScale, float yScale, float zScale){}