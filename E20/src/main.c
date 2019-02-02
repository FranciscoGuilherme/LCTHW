#include <stdlib.h>
#include <stdio.h>
#include "headers/dbg.h"
#include "headers/E20.h"

int main(int argc, char *argv[])
{
	check(argc == 2, "Need an argument.");

	test_debug();
	test_log_err();
	test_log_warn();
	test_log_info();

	check(test_check("E20.c") == 0, "failed with E20.c");
	check(test_check("E20.c") == 0, "failed with E20.c");
	check(test_check(argv[1]) == -1, "failed with argv.");
	check(test_sentinel(1) == 0, "test_sentinel failed.");
	check(test_sentinel(100) == -1, "test_sentinel failed.");
	check(test_check_mem() == -1, "test_check_mem failed.");
	check(test_check_debug() == -1, "test_check_debug failed.");

	return 0;

	error:
	{
		return 1;
	}
}