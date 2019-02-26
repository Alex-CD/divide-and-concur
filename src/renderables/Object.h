//
// Created by alex on 19/02/19.
//

#ifndef DAC_OBJECT_H
#define DAC_OBJECT_H

#include <string>
#include <GL/gl.h>

using namespace std;
class Object {
 public:
  explicit Object(string id);
  float xPos, yPos, zPos;
  float xSize, ySize, zSize;
  string id;
  GLuint bufferSize = 0;
  virtual void generateVertices(float *buffer) = 0;
  virtual void setPos(float xPos, float yPos, float zPos) = 0;
  virtual void translate(float xDistance, float yDistance, float zDistance) = 0;
  virtual void setTransform(float xTransform, float yTransform, float zTransform) = 0;
  virtual void transform(float xFactor, float yFactor, float zFactor) = 0;
  virtual void scale(float scaleFactor) = 0;
  virtual void scale(float xScale, float yScale, float zScale) = 0;
};

#endif //DAC_OBJECT_H
