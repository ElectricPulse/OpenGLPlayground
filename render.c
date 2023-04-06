#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "main.h"
#include "draw.h"

enum Id {RECTANGLE_ID, CIRCLE_ID};

struct Node {
	enum Id id;
	struct Node *next;
	struct Node *prev;
	void *object;
};

struct Node *state = NULL;

void addNode(void *object, enum Id id) {
	struct Node *const node = malloc(sizeof(struct Node));	

	node->id = id;
	node->next = NULL;
	node->object = object;

	if(state == NULL) {
		node->prev = NULL;
		state = node;
		return; 
	}

	struct Node *temp = state;

	while(NULL != temp->next)
		temp = temp->next;
	
	temp->next = node;
	node->prev = temp;
}

struct Rectangle *const drawRectangle(
	coord x1, 
	coord y1, 
	coord x2, 
	coord y2
) {	
	struct Rectangle *const rectangle = malloc(sizeof(struct Rectangle));

	rectangle->x1 = x1;
	rectangle->y1 = y1;
	rectangle->x2 = x2;
	rectangle->y2 = y2;

	addNode(rectangle, RECTANGLE_ID);	
	
	return rectangle;
}

struct Circle *const drawCircle(
	coord x,
	coord y,
	coord r
) {
	struct Circle *const circle = malloc(sizeof(struct Circle));
	
	circle->x = x;
	circle->y = y;
	circle->r = r;
		
	addNode(circle, CIRCLE_ID);
	
	return circle;	
}

void render(void) {
	struct Node *node = state;

	while(NULL != node) {
		switch(node->id) {
			case RECTANGLE_ID: {
				struct Rectangle *rectangle = (struct Rectangle *) node->object;
			
				glBegin(GL_POLYGON);
					glVertex2i(rectangle->x1, rectangle->y1);
					glVertex2i(rectangle->x2, rectangle->y1);
					glVertex2i(rectangle->x2, rectangle->y2);
					glVertex2i(rectangle->x1, rectangle->y2);
				glEnd();
				break;
			}
			case CIRCLE_ID: {
				struct Circle *circle = (struct Circle *) node->object;
				glBegin(GL_POLYGON);
                			for(float radian = 0; radian <= 2 * PI; radian += PI/180) {
						glVertex2i(cos(radian) * circle->r + circle->x, sin(radian) * circle->r + circle->y); 
                
					}
				glEnd();
				break;
			}
			default:
				printf("Unknown object in state list\n");
		}
		
		node = node->next;
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
