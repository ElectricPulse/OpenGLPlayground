#include "screen.h"
#include "events.h"

//Primitives
struct Rectangle {
        unsigned short x1;
        unsigned short y1;
        unsigned short x2;
        unsigned short y2;
};

struct Circle {
        unsigned short x;
        unsigned short y;
        unsigned short r;
};

//Draw functions
struct Rectangle* const drawRectangle(
        unsigned short x1, 
        unsigned short y1, 
        unsigned short x2, 
        unsigned short y2
);

struct Circle* const drawCircle(
        unsigned short x,
        unsigned short y,
        unsigned short r
);


