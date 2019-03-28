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
  Vec3 transform;
  Vec3 position;
  Vec3 velocity;
  Vec3 size;
  float vertices[6];
  WorldObject();
  WorldObject (Vec3 size, Vec3 position, string id);
  void generateVertices(float *buffer);
  void setPos(Vec3 pos);
  void move(Vec3 offset);
  void setTransform(Vec3 transform);
  void scaleBy(float scaleFactor);
  void scaleBy(Vec3 scale);
};

#endif //DAC_SCENEOBJECT_H
