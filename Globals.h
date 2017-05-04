#ifndef GLOBALS_H
#define GLOBALS_H

// 1 meter (box2d) is more or less 64 pixels (sfml)
#define RATIO 30.0f
#define PIXELS_PER_METER RATIO

// 64 pixels (sfml) are more or less 1 meter (box2d)
#define UNRATIO (1.0f/RATIO)
#define METERS_PER_PIXEL UNRATIO

//formula to convert radians to degrees = (radians * (pi/180))
#define RADTODEG 57.295779513082320876f
#define DEGTORAD 0.0174532925199432957f

#define CAR_WIDTH 2.8f

#define XPOS 500
#define YPOS 400

#endif