//
// Created by alex on 28/01/19.
//

#include "Vector.h"

Vector::Vector(float xPos, float yPos, float zPos, string id):WorldObject(xPos, yPos, zPos, id){
  this->bufferSize = 3 * sizeof(int);

}

void Vector::generateVertices(float *vertices) {


  vertices[0] = this->xPos - (xSize/2);
  vertices[1] = this->yPos - (ySize/2);
  vertices[2] = 0.0f;
  vertices[3] = this->xPos;
  vertices[4] = this->yPos + (ySize/2);
  vertices[5] = 0.0f;
  vertices[6] = this->xPos + (xSize/2);
  vertices[7] = this->yPos - (ySize/2);
  vertices[8] = 0.0f;

/*
  vertices[0] = -1.0f;
  vertices[1] = -1.0f;
  vertices[2] = 0.0f;
  vertices[3] =  1.0f;
  vertices[4] = 1.0f;
  vertices[5] =  0.0f;
  vertices[6] = -1.0f;
  vertices[7] = 1.0f;
  vertices[8] = 0.0;*/
}
