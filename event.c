#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "draw.h"

#define PLAYER_SPEED 20 * VH
#define PLAYER_WIDTH 50 * VW
#define PLAYER_HEIGHT 40 * VH
#define BALL_SPEED 100 * VH
#define BORDER 5 * VW

struct Player {
	struct Rectangle *rectangle;
	coord x;
	enum direction {DOWN = 1, UP = -1} direction;
};

struct State {
	double speed;
	double trajectory_angle;
	struct Player player_l;
	struct Player player_r;
	struct Circle *circle;
};

static struct State *state = NULL;

void eventInit(void) {
	state = malloc(sizeof(struct State));
	state->circle = drawCircle(50 * VW,50 * VH, 5 * VW);
	
	state->player_l.rectangle = drawRectangle(
		BORDER, 
		SC_H - BORDER,
		BORDER + PLAYER_WIDTH,
		SC_H - BORDER - PLAYER_HEIGHT
	);

	state->player_l.direction = UP;

	state->player_r.rectangle = drawRectangle(
		SC_W - BORDER - PLAYER_WIDTH, 
		BORDER, 
		SC_W - BORDER, 
		BORDER + PLAYER_HEIGHT
	);
	state->player_r.direction = DOWN;
	
	state->speed = BALL_SPEED * VW/FPS;
	
	time_t t;
	srand((unsigned) time(&t));
	state->trajectory_angle = (double)rand()/(double)(RAND_MAX) * (2 * PI);
}

void moveRectangle(struct Rectangle *rectangle, coord move_x, coord move_y) {
	rectangle->x1 += move_x;
	rectangle->x2 += move_x;
	rectangle->y1 += move_y;
	rectangle->y2 += move_y;
}

void eventLoop(void) {
	state->circle->x += cos(state->trajectory_angle) * state->speed;
	state->circle->y += sin(state->trajectory_angle) * state->speed;
	
	moveRectangle(state->player_l.rectangle, 0, state->player_l.direction * PLAYER_SPEED/FPS);
	moveRectangle(state->player_r.rectangle, 0, (state->player_r.direction) * PLAYER_SPEED/FPS);
	
	//If collides with bottom
	if(state->circle->y + state->circle->r >= SC_H || state->circle->y - state->circle->r <= 0)
		state->trajectory_angle = 2 * PI - state->trajectory_angle;
	if(state->circle->x + state->circle->r >= SC_W || state->circle->x - state->circle->r <= 0)
		state->trajectory_angle = 3/2 * PI - state->trajectory_angle;
}
