//
// Created by alex on 28/01/19.
//

#ifndef DAC_VECTOR_H
#define DAC_VECTOR_H

#include "WorldObject.h"

/**
 * 3D shapes, which exist in the 3D game world.
 * Act as sprites.
 */
class Vector : public WorldObject {
 public:
  Vector(Vec3 pos, Vec3 size, string id);
  Vector(Vec3 colour1, Vec3 colour2, Vec3 colour3, Vec3 pos, Vec3 size, string id);
  Vec3 col1, col2, col3; //Corner colours
  void setColour(Vec3 col1, Vec3 col2, Vec3 col3);
  void generateVertices(float *buffer, int xViewportSize, int yViewportSize);
  bool basicClickDetect(float xClick, float yClick);
};

#endif //DAC_VECTOR_H
