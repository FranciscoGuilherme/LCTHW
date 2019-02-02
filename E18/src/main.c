#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>
#include "headers/E18.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		die("USAGE: EX18 4 3 1 5 6");
	}

	int i = 0;
	int count = argc - 1;
	char **inputs = argv + 1;
	int *numbers = malloc(count * sizeof(int));

	if (!numbers)
	{
		die("Memory error.");
	}

	for (i = 0; i < count; i++)
	{
		numbers[i] = atoi(inputs[i]);
	}

	test_sorting(numbers, count, sorted_order);
	test_sorting(numbers, count, reverse_order);
	test_sorting(numbers, count, strange_order);

	free(numbers);

	return 0;
}