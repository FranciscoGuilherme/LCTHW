#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "headers/E16.h"

int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
	struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

	printf("Joe is at memory location %p:\n", joe);
	printf("Frank is at memory location %p:\n", frank);

	Person_print(joe);
	Person_print(frank);

	Person_update(joe);
	Person_update(frank);

	Person_print(joe);
	Person_print(frank);

	return 0;
}