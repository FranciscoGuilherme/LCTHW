#ifndef _E18_h
#define _E18_h

typedef int (*compare_cb)(int a, int b);

void die(const char *message);
int *bubble_sort(int *numbers, int count, compare_cb cmp);
int sorted_order(int a, int b);
int reverse_order(int a, int b);
int strange_order(int a, int b);
void test_sorting(int *numbers, int count, compare_cb cmp);

#endif