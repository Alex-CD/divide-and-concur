//
// Created by alex on 19/02/19.
//

#ifndef DAC_OBJECT_H
#define DAC_OBJECT_H

#include <string>
#include <GL/gl.h>
#include <Vec3.h>

using namespace std;

/**
 * Virtual base class for all logical objects used in games.
 */
class Object {
 public:
  explicit Object(string id);
  Vec3 pos;
  Vec3 size;
  Vec3 transform;
  string id;
  GLuint bufferSize = 0;
  virtual void generateVertices(float *buffer, int xViewportSize, int yViewportSize) = 0;
  virtual void setPos(Vec3 pos) = 0;
  virtual void setPos(float xPos, float yPos, float zPos) = 0;
  virtual void move(Vec3 distance) = 0;
  virtual void move(float xDistance, float yDistance, float zDistance) = 0;
  virtual void setTransform(float xTransform, float yTransform, float zTransform) = 0;
  virtual void scaleBy(float scaleFactor) = 0;
  virtual void scaleBy(Vec3 scaleFactor) = 0;
  virtual void scaleBy(float xScale, float yScale, float zScale) = 0;
};

#endif //DAC_OBJECT_H
