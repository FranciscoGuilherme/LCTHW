#include <stdio.h>
#include <dlfcn.h>
#include "../shared/dbg.h"

typedef struct Library
{
	char *file;
	char *func;
	char *data;
	void *lib;
} Library;

typedef int (*lib_function)(const char *data);

int main(int argc, char *argv[])
{
	check(argc == 4, "USAGE: <executable> <lib.so> <function> <data>");

	int rc = 0;

	Library library =
	{
		.file = argv[1],
		.func = argv[2],
		.data = argv[3],
		.lib = dlopen(library.file, RTLD_NOW)
	};

	check(library.lib != NULL, "Failed to open the library %s: %s", library.file, dlerror());

	lib_function func = dlsym(library.lib, library.func);

	check(func != NULL, "Did not find %s function in the librari %s", library.func, library.file);

	rc = func(library.data);

	check(rc == 0, "Function %s return %d for data: %s", library.func, rc, library.data);

	rc = dlclose(library.lib);

	check(rc == 0, "Failed to close %s", library.file);

	return 0;

	error:
	{
		return 1;
	}
}