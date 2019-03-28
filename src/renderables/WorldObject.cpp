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
 * Constructor for WorldObjects
 * @param xSize Diameter of the object in the x plane.
 * @param ySize Diameter of the object in the y plane.
 * @param zSize Diameter of the object in the z plane.
 */
WorldObject::WorldObject(Vec3 size, Vec3 position, string id):Object(id){

  this->pos = position;
  this->size = size;
  this->transform = Vec3(1.0f, 1.0f, 1.0f);
};


/**
 * Sets the position of this world object, relative to the center of the window.
 * @param xPos X-coord of this object in Px
 * @param yPos Y-coord of this object in Px
 * @param zPos Z-coord of this object in Px
 */
void WorldObject::setPos(Vec3 pos) {
  this->pos = pos;
}

/**
 *
 * @param xPos
 * @param yPos
 * @param zPos
 */
void WorldObject::setPos(float xPos, float yPos, float zPos) {
  this->setPos(Vec3(xPos, yPos, zPos));
}

/**
 * Moves this object a distance (in px)
 * @param xDistance Distance to move (in the x plane)
 * @param yDistance Distance to move. (in the y plane)
 * @param zDistance Distnace to move. (in the z plane)
 */
void WorldObject::move(Vec3 offset) {
  this->pos.x += offset.x;
  this->pos.y += offset.y;
  this->pos.z += offset.z;
}


void WorldObject::move(float xDistance, float yDistance, float zDistance) {
  this->move(Vec3(xDistance, yDistance, zDistance));
}


/**
 * Scales the object by a factor (taking into account current scaling), preserving aspect ratio.
 * @param scaleFactor Factor to scale by.
 */
void WorldObject::scaleBy(float scaleFactor) {
  this->scaleBy(Vec3(scaleFactor, scaleFactor, scaleFactor));
}

/**
 *
 * @param scaleFactorX
 * @param scaleFactorY
 * @param scaleFactorZ
 */
void WorldObject::scaleBy(float xScale, float yScale, float zScale) {
  this->scaleBy(Vec3(xScale, yScale, zScale));
}

void WorldObject::scaleBy(Vec3 scaleFactor) {
  this->transform.x *= scaleFactor.x;
  this->transform.x *= scaleFactor.y;
  this->transform.x *= scaleFactor.z;
}

/**
 * Sets the scale factors of this object.
 * @param xTransform Factor to scale by, in the x plane.
 * @param yTransform Factor to scale by, in the y plane
 * @param zTransform Factor to scale by, in the z plane
 */
void WorldObject::setTransform(Vec3 scaleFactor) {
  this->transform.x = scaleFactor.x;
  this->transform.y = scaleFactor.y;
  this->transform.z = scaleFactor.z;
}


void WorldObject::setTransform(float xTransform, float yTransform, float zTransform) {
  setTransform(Vec3(xTransform, yTransform, zTransform));
}