#include <unistd.h>

int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	int i = 0;

	while(i < 100)
	{
		i++;
		usleep(3000);
	}

	return 0;
}