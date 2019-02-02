#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	int num_states = 4;
	char *states[] =
	{
		"California", "Oregon",
		"Washington", "Texas"
	};
	
	for(i = 0; i < argc; i++) printf("arg %d: %s\n", i, argv[i]);
	for(i = 0; i < num_states; i++) printf("state %d: %s\n", i, states[i]);

	return 0;
}
