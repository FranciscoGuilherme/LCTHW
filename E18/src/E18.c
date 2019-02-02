#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>
#include "headers/E18.h"

void die(const char *message)
{
	if (errno)
	{
		perror(message);

		exit(1);
	}

	printf("ERROR: %s\n", message);

	exit(1);
}

int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
	int temp = 0;
	int i = 0;
	int j = 0;
	int *target = malloc(count * sizeof(int));

	if (!target)
	{
		die("Memory error.");
	}

	memcpy(target, numbers, count * sizeof(int));

	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count - 1; j++)
		{
			if (cmp(target[j], target[j + 1]) > 0)
			{
				temp = target[j + 1];
				target[j + 1] = target[j];
				target[j] = temp;
			}
		}
	}

	return target;
}

int sorted_order(int a, int b)
{
	return a - b;
}

int reverse_order(int a, int b)
{
	return b - a;
}

int strange_order(int a, int b)
{
	if (a == 0 || b == 0)
	{
		return 0;
	}

	return a % b;
}

void test_sorting(int *numbers, int count, compare_cb cmp)
{
	int i = 0;
	int *sorted = bubble_sort(numbers,  count, cmp);

	if (!sorted)
	{
		die("Failed to sort as requested.");
	}

	for (i = 0; i < count; i++)
	{
		printf("%d ", sorted[i]);
	}

	printf("\n");

	free(sorted);
}