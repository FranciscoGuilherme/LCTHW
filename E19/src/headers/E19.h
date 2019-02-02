#ifndef _E19_h
#define _E19_h

#include "object.h"

typedef struct Monster
{
	Object proto;
	int hit_points;
} Monster;

typedef struct Room
{
	Object proto;
	Monster *bad_guy;

	struct Room *north;
	struct Room *south;
	struct Room *east;
	struct Room *west;
} Room;

typedef struct Map
{
	Object proto;
	Room *start;
	Room *location;
} Map;

int Monster_attack(void *self, int damage);
int Monster_init(void *self);

void *Room_move(void *self, Direction direction);
int Room_attack(void *self, int damage);
int Room_init(void *self);

void *Map_move(void *self, Direction direction);
int Map_attack(void *self, int damage);
int Map_init(void *self);

int process_input(Map *game);

#endif
