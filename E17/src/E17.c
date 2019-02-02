#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "headers/E17.h"

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

void Address_print(struct Address *addr)
{
	printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);

	if (rc != 1)
	{
		die("Failed to load database.");
	}
}

struct Connection *Database_open(const char *filename, char mode)
{
	struct Connection *conn = malloc(sizeof(struct Connection));

	if (!conn)
	{
		die("Memory error");
	}

	conn->db = malloc(sizeof(struct Database));

	if (!conn->db)
	{
		die("Memory error");
	}

	switch (mode)
	{
		case 'c': conn->file = fopen(filename, "w"); break;
		default:
		{
			conn->file = fopen(filename, "r+");

			if (conn->file)
			{
				Database_load(conn);
			}
		}
	}

	if (!conn->file)
	{
		die("Fail to open the file");
	}

	return conn;
}

void Database_close(struct Connection *conn)
{
	if (conn)
	{
		if (conn->file)
		{
			fclose(conn->file);
		}

		if (conn->db)
		{
			free(conn->db);
		}

		free(conn);
	}
}

void Database_write(struct Connection *conn)
{
	rewind(conn->file);

	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);

	if (rc != 1)
	{
		die("Failed to write database");
	}

	rc = fflush(conn->file);

	if (rc == -1)
	{
		die("Cannot flush database.");
	}
}

void Database_create(struct Connection *conn)
{
	int i = 0;

	for ( ; i < MAX_ROWS; i++)
	{
		struct Address addr =
		{
			.id = i,
			.set = 0
		};

		conn->db->rows[i] = addr;
	}
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
	struct Address *addr = &conn->db->rows[id];

	if (addr->set)
	{
		die("Already set, delete it first");
	}

	addr->set = 1;

	char *res = strncpy(addr->name, name, MAX_DATA);

	if (!res)
	{
		die("Name copy failed");
	}

	res = strncpy(addr->email, email, MAX_DATA);

	if (!res)
	{
		die("Email copy failed");
	}
}

void Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &conn->db->rows[id];

	if (!addr->set)
	{
		die("ID is not set");
	}

	Address_print(addr);
}

void Database_delete(struct Connection *conn, int id)
{
	struct Address addr =
	{
		.id = id,
		.set = 0
	};

	conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
	int i = 0;

	struct Database *db = conn->db;

	for ( ; i < MAX_ROWS; i++)
	{
		struct Address *cur = &db->rows[i];

		if (cur->set)
		{
			Address_print(cur);
		}
	}
}