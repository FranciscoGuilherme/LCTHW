#ifndef _tstree_h
#define _tstree_h

#include <stdlib.h>
#include "darray.h"

typedef struct TSTree
{
	char splitchar;
	struct TSTree *low;
	struct TSTree *equal;
	struct TSTree *high;
	void *value;
} TSTree;

typedef void (*TSTree_traverse_cb)(void *value, void *data);

TSTree *TSTree_insert(TSTree *node, const char *key, size_t len, void *value);
void *TSTree_search(TSTree *root, const char *key, size_t len);
void *TSTree_search_prefix(TSTree *root, const char *key, size_t len);
void TSTree_traverse(TSTree *nood, TSTree_traverse_cb cb, void *data);
void TSTree_destroy(TSTree *root);

#endif