//
// Created by alex on 28/01/19.
//

#ifndef DAC_BITMAP_H
#define DAC_BITMAP_H

#include "ScreenObject.h"

/**
 *
 */
class TexturedShape:public ScreenObject{
 public:
  TexturedShape(float xPos, float yPos, float zPos, string id);
};

#endif //DAC_BITMAP_H
