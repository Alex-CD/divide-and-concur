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
  ScreenObject(Vec3 pos, Vec3 size, string id);
  void generateVertices(float *buffer, int xViewportSize, int yViewportSize);
  void setPos(Vec3 pos);
  void translate(Vec3 distance);
  void setTransform(Vec3 transform);
  void scaleBy(float scaleFactor);
  void scaleBy(Vec3 transform);

};

#endif //DAC_SCREENOBJECT_H
