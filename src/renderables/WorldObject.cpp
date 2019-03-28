//
// Created by alex on 21/01/19.
//

#include "WorldObject.h"



WorldObject::WorldObject(string id):Object(id) {
  this->pos = Vec3(0.0f, 0.0f, 0.0f);
  this->size = Vec3(100.0f, 100.0f, 100.0f);
  this->transform = Vec3(1.0f, 1.0f, 1.0f);
}
/**
 * Constructor for the worldObject class.
 * @param size Size of the object to create
 * @param position Position of the created object
 * @param id Id of the object to create
 */
WorldObject::WorldObject(Vec3 size, Vec3 position, string id):Object(id){

  this->pos = position;
  this->size = size;
  this->transform = Vec3(1.0f, 1.0f, 1.0f);
};


/**
 * Sets the position of this object, in px, relative to the center of the screen.
 * @param pos position to move this object to.
 */
void WorldObject::setPos(Vec3 pos) {
  this->pos = pos;
}

/**
 * Sets the position of this object, in px, relative to the center of the screen.
 * @param xPos Y coordinate in px where this object will be moved to.
 * @param yPos X coordinate in px where this object will be moved to.
 * @param zPos Z coordinate in px where this object will be moved to.
 */
void WorldObject::setPos(float xPos, float yPos, float zPos) {
  this->setPos(Vec3(xPos, yPos, zPos));
}

/**
 * Moves this object by a given distance(vector).
 * @param offset Distance to move this object.
 */
void WorldObject::move(Vec3 offset) {
  this->pos.x += offset.x;
  this->pos.y += offset.y;
  this->pos.z += offset.z;
}

/**
 * Moves this object by a given distance (vector).
 * @param xDistance Distance to move in the X plane.
 * @param yDistance Distance to move in the Y plane.
 * @param zDistance Distance to move in the Z plane.
 */
void WorldObject::move(float xDistance, float yDistance, float zDistance) {
  this->move(Vec3(xDistance, yDistance, zDistance));
}


/**
 * Multiplies the size of the current object by the given factor, preserving aspect ratio.
 * Takes into account existing scaling (ie compound scaling)
 * @param scaleFactor Factor to scale by.
 */
void WorldObject::scaleBy(float scaleFactor) {
  this->scaleBy(Vec3(scaleFactor, scaleFactor, scaleFactor));
}

/**
 * Multiplies the size of the current object by the given factor (in each plane).
 * Takes into account existing scaling (ie compound scaling).
 * @param scaleFactorX Factor to scale by, in the X plane.
 * @param scaleFactorY Factor to scale by, in the Y plane.
 * @param scaleFactorZ Factor to scale by, in the Z plane.
 */
void WorldObject::scaleBy(float xScale, float yScale, float zScale) {
  this->scaleBy(Vec3(xScale, yScale, zScale));
}

/**
 * Multiplies the size of the current object by the given factor (in each plane)
 * @param scaleFactor Factor to scale by.
 */
void WorldObject::scaleBy(Vec3 scaleFactor) {
  this->transform.x *= scaleFactor.x;
  this->transform.x *= scaleFactor.y;
  this->transform.x *= scaleFactor.z;
}

/**
 * Sets the transform of this object.
 * Size is multiplied by the transform to calculate how large an object should be when rendered.
 * Multiplies pre-perspective matrix transformation.
 * @param scale Factor Factors to scale by.
 */
void WorldObject::setTransform(Vec3 scaleFactor) {
  this->transform.x = scaleFactor.x;
  this->transform.y = scaleFactor.y;
  this->transform.z = scaleFactor.z;
}


/**
 * Sets the transform of this object.
 * Size is multiplied by the transform to calculate how large an object should be when rendered.
 * Multiplies pre-perspective matrix transformation.
 * @param xTransform Factor to scale by, in the X plane.
 * @param yTransform Factor to scale by, in the Y plane.
 * @param zTransform Factor to scale by, in the Z plane.
 */
void WorldObject::setTransform(float xTransform, float yTransform, float zTransform) {
  setTransform(Vec3(xTransform, yTransform, zTransform));
}