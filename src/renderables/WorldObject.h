//
// Created by alex on 21/01/19.
//

#ifndef DAC_SCENEOBJECT_H
#define DAC_SCENEOBJECT_H

#include "Object.h"

class WorldObject:public Object{
 public:
  float xTransform, yTransform, zTransform;
  float vertices[6];
  WorldObject (float xSize, float ySize, float zSize, string id);
  void generateVertices(float *buffer);
  void setPos(float xPos, float yPos, float zPos);
  void translate(float xDistance, float yDistance, float zDistance);
  void setTransform(float xTransform, float yTransform, float zTransform);
  void transform(float xFactor, float yFactor, float zFactor);
  void scale(float scaleFactor);
  void scale(float xScale, float yScale, float zScale);
};

#endif //DAC_SCENEOBJECT_H
