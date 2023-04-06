#include "screen.h"
#include "events.h"

#define PI 3.14

typedef float coord;

//Primitives
struct Rectangle {
        coord x1;
        coord y1;
        coord x2;
        coord y2;
};

struct Circle {
        coord x;
        coord y;
        coord r;
};

//Draw functions
struct Rectangle* const drawRectangle(
        coord x1, 
        coord y1, 
        coord x2, 
        coord y2
);

struct Circle* const drawCircle(
        coord x,
        coord y,
        coord r
);

