#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "main.h"

enum Id {RECTANGLE_ID, CIRCLE_ID};

void *state = NULL;

struct Node {
	enum Id id;
	void *next;
	void *prev;
};

struct Rectangle {
	struct Node node;
	unsigned short x1;
	unsigned short y1;
	unsigned short x2;
	unsigned short y2;
};

void drawRectangle(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2) {
	if(NULL == state) {
		struct Rectangle *const rectangle = malloc(sizeof(struct Rectangle));
		rectangle->node.id = RECTANGLE_ID;
		rectangle->node.next = NULL;
		rectangle->node.prev = NULL;
		rectangle->x1 = x1;
		rectangle->y1 = y1;
		rectangle->x2 = x2;
		rectangle->y2 = y2;
		
		state = rectangle;
	}
}

struct Dummy {
	struct Node node;
};	

void render(void) {
	struct Dummy *object = state;
	struct Rectangle *rectangle = (struct Rectangle *) object;
	while(NULL != object) {
		switch(object->node.id) {
			case RECTANGLE_ID:
				glBegin(GL_POLYGON);
					glVertex2i(rectangle->x1, rectangle->y1);
					glVertex2i(rectangle->x2, rectangle->y1);
					glVertex2i(rectangle->x2, rectangle->y2);
					glVertex2i(rectangle->x1, rectangle->y2);
				glEnd();
			break;
			default:
				printf("Unknown object in state list\n");
		}
		
		object = object->node.next;
	}	
}

//Code to draw circle:  
/*
//GL_POINTS each vertex is a point
//GL_LINE each pair of vertices is a line
        //GL_LINE_STRIP all vertices make a line
	
        int radius = SC_W/16;
        int x_i = SC_W/2;
	int y_i = SC_H/2;
        glBegin(GL_POINTS);
                for(float radian = 0; radian <= 2 * PI; radian += PI/180) {
                        glVertex2i(cos(radian) * radius + x_i, sin(radian) * radius + y_i); 
                
	}
        glEnd();
*/
