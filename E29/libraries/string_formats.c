#include <stdio.h>
#include <ctype.h>
#include "../shared/dbg.h"

int print_a_message(const char *msg)
{
	printf("A STRING: %s\n", msg);

	return 0;
}

int uppercase(const char *msg)
{
	int i = 0;

	for (i = 0; msg[i] != '\0'; i++)
	{
		printf("%c", toupper(msg[i]));
	}

	printf("\n");

	return 0;
}

int lowercase(const char *msg)
{
	int i = 0;

	for (i = 0; msg[i] != '\0'; i++)
	{
		printf("%c", tolower(msg[i]));
	}

	printf("\n");

	return 0;
}

int fail_on_purpose(const char *msg)
{
	check(msg != NULL, "Mensagem nao fornecida.");

	return 1;

	error:
		return 1;
}