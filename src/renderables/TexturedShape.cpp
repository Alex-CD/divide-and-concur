#include "ScreenObject.h"
#include "TexturedShape.h"

/**
 * Constructor for textured shapes.
 * @param xPos Position of the object in the X axis, relative to the center of the frame (in pixels)
 * @param yPos Position of the object in the X axis, relative to the center of the frame (in pixels)
 * @param id Id of the texturedshape.
 */
TexturedShape::TexturedShape(int xPos, int yPos, string id):ScreenObject(xPos, yPos, 1, 1, id) {

}