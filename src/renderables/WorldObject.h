//
// Created by alex on 21/01/19.
//

#ifndef DAC_SCENEOBJECT_H
#define DAC_SCENEOBJECT_H

#include "Object.h"

#include "Vec3.h"

/**
 * Parent class for objects that exist in the 3D world.
 */
class WorldObject:public Object{
 public:
  Vec3 velocity;
  float vertices[6];
  explicit WorldObject(string id);
  WorldObject (Vec3 size, Vec3 position, string id);
  void setPos(Vec3 pos);
  void setPos(float xPos, float yPos, float zPos);
  void move(Vec3 offset);
  void move(float xDistance, float yDistance, float zDistance);
  void setTransform(Vec3 scaleFactor);
  void setTransform(float xTransform, float yTransform, float zTransform);
  void scaleBy(float scaleFactor);
  void scaleBy(Vec3 scaleFactor);
  void scaleBy(float xScale, float yScale, float zScale);
};

#endif //DAC_SCENEOBJECT_H
