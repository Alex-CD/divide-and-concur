//
// Created by alex on 21/01/19.
//

#ifndef DAC_SCENEOBJECT_H
#define DAC_SCENEOBJECT_H

class WorldObject {
 private:
  float xPos, yPos, zPos;
  float xSize, ySize, zSize;
  float xTransform, yTransform, zTransform;


 public:
  WorldObject(float xSize, float ySize, float zSize);
  void setPos(float xPos, float yPos, float zPos);
  void translate(float xDistance, float yDistance, float zDistance);
  void setTransform(float xTransform, float yTransform, float zTransform);
  void transform(float xFactor, float yFactor, float zFactor);
  void scale(float scaleFactor);
};

#endif //DAC_SCENEOBJECT_H
