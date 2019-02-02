#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "headers/E17.h"

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		die("USAGE: ex17 <dbfile> <action> [action params]");
	}

	int id = 0;
	char *filename = argv[1];
	char action = argv[2][0];
	struct Connection *conn = Database_open(filename, action);

	if (argc > 3)
	{
		id = atoi(argv[3]);
	}

	if (id >= MAX_ROWS)
	{
		die("There is not that many records.");
	}

	switch (action)
	{
		case 'c':
		{
			Database_create(conn);
			Database_write(conn);

			break;
		}
		case 'g':
		{
			if (argc != 4)
			{
				die("Need an id to get");
			}

			Database_get(conn, id);

			break;
		}
		case 's':
		{
			if (argc != 6)
			{
				die("Need id, name, email to set");
			}

			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);

			break;
		}
		case 'd':
		{
			if (argc != 4)
			{
				die("Need id to delete");

				Database_delete(conn, id);
				Database_write(conn);
			}

			break;
		}
		case 'l':
		{
			Database_list(conn);

			break;
		}
		default: die("Invalid action, only: c=create, g=get, s=set, d=del, l=list");
	}

	Database_close(conn);

	return 0;
}