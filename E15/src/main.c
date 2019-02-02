#include <stdio.h>

#define NLINE(M) puts(# M)

int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	int i = 0;
	int ages[] = { 23, 43, 12, 89, 2 };
	int count = sizeof(ages) / sizeof(int);
	char *names[] = { "Alan", "Frank", "Mary", "John", "Lisa" };
	int *cur_age = ages;
	char **cur_name = names;

	for (i = 0; i < count; i++)
	{
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}
		
	NLINE(---);

	for (i = 0; i < count; i++)
	{
		printf("%s has %d years alive.\n", *(cur_name + i), *(cur_age + i));
	}
		
	NLINE(---);

	for (i = 0; i < count; i++)
	{
		printf("%s has %d years alive.\n", cur_name[i], cur_age[i]);
	}
		
	NLINE(---);

	for (cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++)
	{
		printf("%s has %d years alive.\n", *cur_name, *cur_age);
	}

	return 0;
}