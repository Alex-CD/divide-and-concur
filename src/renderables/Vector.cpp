//
// Created by alex on 28/01/19.
//

#include "Vector.h"

Vector::Vector(float xPos, float yPos, float zPos, string id):WorldObject(xPos, yPos, zPos, id){

}

void Vector::generateVertices(float *vertices) {
  vertices[0] = this->xPos - (xSize/2);
  vertices[1] = this->yPos - (ySize/2);
  vertices[2] = 0;
  vertices[3] = this->xPos + (xSize/2);
  vertices[4] = this->yPos - (ySize/2);
  vertices[5] = 0;
  vertices[6] = this->xPos;
  vertices[7] = this->yPos - (ySize/2);
  vertices[8] = 0;
}