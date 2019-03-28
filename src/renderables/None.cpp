//
// Created by alex on 28/01/19.
//

#include "None.h"

None::None():Object(""){
  this->bufferSize = 0;
}

void None::generateVertices(float *buffer, int xViewportSize, int yViewportSize){}
void None::setPos(Vec3 pos){}
void None::translate(Vec3 distance){}
void None::setTransform(Vec3 transform){}
void None::scaleBy(float scaleFactor){}
void None::scaleBy(Vec3 transform){}
