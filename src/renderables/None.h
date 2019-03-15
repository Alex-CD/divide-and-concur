//
// Created by alex on 28/01/19.
//

#ifndef DAC_NONE_H
#define DAC_NONE_H

#include "Object.h"

/**
 * A game object that does nothing - to be used as a placeholder.
 * All of the methods are empty.
 */
class None: public Object {
 public:
  None();
  GLuint bufferSize = 0;
  void generateVertices(float *buffer, int xViewportSize, int yViewportSize);
  void setPos(int xPos, int yPos, int zPos);
  void translate(float xDistance, float yDistance, float zDistance);
  void setTransform(float xTransform, float yTransform, float zTransform);
  void transform(float xFactor, float yFactor, float zFactor);
  void scale(float scaleFactor);
  void scale(float xScale, float yScale, float zScale);
};

#endif //DAC_NONE_H
