//
// Created by alex on 22/02/19.
//

#ifndef DAC_SCREENOBJECT_H
#define DAC_SCREENOBJECT_H

#include "Object.h"

/**
 * Parent class for all of the objects who exist in the 2D plane on the screen,
 * and whose position is relative to the screen rather than the 3D game world/camera.
 */
class ScreenObject:public Object{
 public:
  ScreenObject(int xPos, int yPos, int xSize, int ySize, string id);
  void generateVertices(float *buffer, int xViewportSize, int yViewportSize);
  void setPos(float xPos, float yPos, float zPos);
  void translate(float xDistance, float yDistance, float zDistance);
  void setTransform(float xTransform, float yTransform, float zTransform);
  void transform(float xFactor, float yFactor, float zFactor);
  void scale(float scaleFactor);
  void scale(float xScale, float yScale, float zScale);

};

#endif //DAC_SCREENOBJECT_H
