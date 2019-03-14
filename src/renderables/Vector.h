//
// Created by alex on 28/01/19.
//

#ifndef DAC_VECTOR_H
#define DAC_VECTOR_H

#include "WorldObject.h"

class Vector : public WorldObject {
 public:
  Vector(float xPos, float yPos, float zPos, string id);
  void generateVertices(float *vertices, int xViewportSize, int yViewportSize);
  bool basicCollisionDetect(float xClick, float yClick);
};

#endif //DAC_VECTOR_H
