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
  GLuint bufferSize = 0;
  void generateVertices(float *buffer, int xViewportSize, int yViewportSize);
  void setPos(Vec3 pos);
  void translate(Vec3 distance);
  void setTransform(Vec3 transform);
  void scaleBy(float scaleFactor);
  void scaleBy(Vec3 transform);
};

#endif //DAC_NONE_H
