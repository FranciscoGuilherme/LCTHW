#ifndef _E16_h
#define _E16_h

struct Person
{
	char *name;
	int age;
	int height;
	int weight;
};

void Person_update(struct Person *who);
void Person_destroy(struct Person *who);
void Person_print(struct Person *who);
struct Person *Person_create(char *name, int age, int height, int weight);

#endif