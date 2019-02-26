//
// Created by alex on 22/02/19.
//

#ifndef DAC_SCREENOBJECT_H
#define DAC_SCREENOBJECT_H

#include "Object.h"

class ScreenObject:public Object{
 public:
  ScreenObject(float xPos, float yPos, float xSize, float ySize, string id);
  void generateVertices(float *buffer);
  void setPos(float xPos, float yPos, float zPos);
  void translate(float xDistance, float yDistance, float zDistance);
  void setTransform(float xTransform, float yTransform, float zTransform);
  void transform(float xFactor, float yFactor, float zFactor);
  void scale(float scaleFactor);
  void scale(float xScale, float yScale, float zScale);

};

#endif //DAC_SCREENOBJECT_H
