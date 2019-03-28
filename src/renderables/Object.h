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
  virtual void translate(Vec3 distance) = 0;
  virtual void setTransform(Vec3 transform) = 0;
  virtual void scaleBy(float scaleFactor) = 0;
  virtual void scaleBy(Vec3 transform) = 0;
};

#endif //DAC_OBJECT_H
