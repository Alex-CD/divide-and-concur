//
// Created by alex on 22/02/19.
//

#include <Vec3.h>
#include "ScreenObject.h"


/**
 * Constructor for the screenobject parent class.
 * @param xPos X-coord of the object, in pixels, relative to the center of the screen.
 * @param yPos Y-coord of the object, in pixels, relative to the center of the screen.
 * @param xSize Size of the object (in the X-plane) in pixels.
 * @param ySize Size of the object (in the Y-plane) in pixels.
 * @param id Id of this object.
 */
ScreenObject::ScreenObject(Vec3 pos, Vec3 size, string id):Object(id){
  this->pos = pos;
  this->size = size;
  this->transform = Vec3();

}

//TODO
void ScreenObject::generateVertices(float *buffer, int xViewportSize, int yViewportSize) {}
void ScreenObject::setPos(Vec3 pos){}
void ScreenObject::translate(Vec3 distance){}
void ScreenObject::setTransform(Vec3 transform){}
void ScreenObject::scaleBy(float scaleFactor){}
void ScreenObject::scaleBy(Vec3 scale){}