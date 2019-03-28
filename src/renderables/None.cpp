//
// Created by alex on 28/01/19.
//

#include "None.h"

None::None():Object(""){

}

void None::generateVertices(float *buffer, int xViewportSize, int yViewportSize){}
void None::setPos(Vec3 pos){}
void None::setPos(float xPos, float yPos, float zPos){}
void None::move(Vec3 distance){}
void None::move(float xDistance, float yDistance, float zDistance){}
void None::setTransform(float xTransform, float yTransform, float zTransform){}
void None::scaleBy(float scaleFactor){}
void None::scaleBy(Vec3 scaleFactor){}
void None::scaleBy(float xScale, float yScale, float zScale){}