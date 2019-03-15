#ifndef DAC_BITMAP_H
#define DAC_BITMAP_H

#include "ScreenObject.h"

/**
 * A 2D image appearing on the screen.
 */
class TexturedShape:public ScreenObject{
 public:
  TexturedShape(int xPos, int yPos, string id);
};

#endif //DAC_BITMAP_H
