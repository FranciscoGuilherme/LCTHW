#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "headers/dbg.h"
#include "headers/E25.h"

int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	int age = 0;
	char initial = ' ';
	char *first_name = NULL;
	char *last_name = NULL;

	printf("What's your first name? ");

	int rc = read_scan("%s", MAX_DATA, &first_name);

	check(rc == 0, "Failed first name.");

	printf("What's your initial? ");

	rc = read_scan("%c\n", &initial);

	check(rc == 0, "Failed initial.");

	printf("What's your last name? ");

	rc = read_scan("%s", MAX_DATA, &last_name);

	check(rc == 0, "Failed last name.");

	printf("How old are you? ");

	rc = read_scan("%d", &age);

	printf("---- RESULTS ----\n");

	printf("First Name: %s" , first_name);
	printf("Initial: '%c'\n", initial);
	printf("Last Name: %s"  , last_name);
	printf("Age: %d\n"      , age);

	free(first_name);
	free(last_name);

	return 0;

	error:
	{
		return -1;
	}
}