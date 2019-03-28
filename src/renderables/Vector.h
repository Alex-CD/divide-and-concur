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
  Vector(float xPos, float yPos, float zPos, string id);
  float rCol, gCol, bCol;
  void setColour(float rCol, float gCol, float bCol);
  void generateVertices(float *buffer, int xViewportSize, int yViewportSize);
  bool basicClickDetect(float xClick, float yClick);
};

#endif //DAC_VECTOR_H
