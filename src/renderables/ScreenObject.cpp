//
// Created by alex on 22/02/19.
//

#include <Vec3.h>
#include "ScreenObject.h"



/**
 * Constructor for the screenObject class
 * @param pos position of the created object
 * @param size Size of the created object (in px)
 * @param id identifier of the created object
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