#include <stdio.h>

#include "draw.h"

struct Circle *circle;

void eventInit(void) {
	//drawRectangle(SC_W/4, SC_H/4, 3 * SC_W/4, 3 * SC_H/4);
	//drawRectangle(0, 0, SC_W, SC_H/4);
	circle = drawCircle(SC_W/2, 0, SC_W/4);
}

void eventLoop(void) {
	//12 seconds to go from top to bottom
	if(circle->y <= SC_H)
		circle->y += SC_H/(5 * FPS);
}
