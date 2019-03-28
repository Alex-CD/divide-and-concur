//
// Created by alex on 21/01/19.
//

#include "WorldObject.h"



WorldObject::WorldObject():Object(id) {
  this->position = Vec3(0.0f, 0.0f, 0.0f);
  this->size = Vec3(0.0f, 0.0f, 0.0f);
  this->transform = Vec3(0.0f, 0.0f, 0.0f);
}
/**
 * Constructor for WorldObjects
 * @param xSize Diameter of the object in the x plane.
 * @param ySize Diameter of the object in the y plane.
 * @param zSize Diameter of the object in the z plane.
 */
WorldObject::WorldObject(Vec3 size, Vec3 position, string id):Object(id){

  this->position = position;
  this->size = size;
  this->transform = Vec3(0.0f, 0.0f, 0.0f);
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

/**
 * Scales the object by a factor (taking into account current scaling), preserving aspect ratio.
 * @param scaleFactor Factor to scale by.
 */
void WorldObject::scaleBy(float scaleFactor) {
  this->transform.x *= scaleFactor;
  this->transform.y *= scaleFactor;
  this->transform.z *= scaleFactor;
}

/**
 *
 * @param scaleFactorX
 * @param scaleFactorY
 * @param scaleFactorZ
 */
void WorldObject::scaleBy(Vec3 scale) {
  this->transform.x *= scale.x;
  this->transform.y *= scale.y;
  this->transform.z *= scale.z;
}

/**
 * Sets the scale factors of this object.
 * @param xTransform Factor to scale by, in the x plane.
 * @param yTransform Factor to scale by, in the y plane
 * @param zTransform Factor to scale by, in the z plane
 */
void WorldObject::setTransform(Vec3 transform) {
  this->transform.x = transform.x;
  this->transform.y = transform.y;
  this->transform.z = transform.z;
}

/**
 * Generates the vertices for this object,
 * outputs into the given buffer.
 * @param buffer Buffer to store vertices in.
 */
void WorldObject::generateVertices(float *buffer) {
  // TODO
}