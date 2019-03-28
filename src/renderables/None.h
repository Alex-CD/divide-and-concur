//
// Created by alex on 28/01/19.
//

#ifndef DAC_NONE_H
#define DAC_NONE_H

#include "Object.h"

/**
 * A game object that does nothing - to be used as a placeholder.
 * All of its member functions can be called, but do nothing.
 */
class None: public Object {
 public:
  None();
  void generateVertices(float *buffer, int xViewportSize, int yViewportSize);
  void setPos(Vec3 pos);
  void setPos(float xPos, float yPos, float zPos);
  void move(Vec3 distance);
  void move(float xDistance, float yDistance, float zDistance);
  void setTransform(float xTransform, float yTransform, float zTransform);
  void scaleBy(float scaleFactor);
  void scaleBy(Vec3 scaleFactor);
  void scaleBy(float xScale, float yScale, float zScale);
};

#endif //DAC_NONE_H
