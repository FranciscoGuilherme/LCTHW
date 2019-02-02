#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headers/E19.h"

Object MapProto =
{
	.init = Map_init,
	.move = Map_move,
	.attack = Map_attack
};

int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	
	srand(time(NULL));

	Map *game = NEW(Map, "The Hall of Minotaur");

	printf("You enter the ");

	game->location->_(describe)(game->location);

	while (process_input(game));

	return 0;
}