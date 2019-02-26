//
// Created by alex on 28/01/19.
//

#include "None.h"

None::None():Object(""){
  this->bufferSize = 0;
}

void None::generateVertices(float *buffer){}
void None::setPos(float xPos, float yPos, float zPos){}
void None::translate(float xDistance, float yDistance, float zDistance){}
void None::setTransform(float xTransform, float yTransform, float zTransform){}
void None::transform(float xFactor, float yFactor, float zFactor){}
void None::scale(float scaleFactor){}
void None::scale(float xScale, float yScale, float zScale){}
