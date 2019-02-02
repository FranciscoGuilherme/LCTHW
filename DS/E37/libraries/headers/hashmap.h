#ifndef _hashmap_h
#define _hashmap_h

#include <stdint.h>
#include "darray.h"

#define DEFAULT_NUMBER_OF_BUCKETS 100

typedef int (*Hashmap_compare)(void *a, void *b);
typedef uint32_t (*Hashmap_hash)(void *key);

typedef struct Hashmap
{
	DArray *buckets;
	Hashmap_compare compare;
	Hashmap_hash hash;
} Hashmap;

typedef struct HashmapNode
{
	void *key;
	void *data;
	uint32_t hash;
} HashmapNode;

typedef int (*Hashmap_transverse_cb)(Hashmap *node);

Hashmap *Hashmap_create(Hashmap_compare compare, Hashmap_hash);
void Hashmap_destroy(Hashmap *map);
int Hashmap_set(Hashmap *map, void *key, void *data);
void *Hashmap_get(Hashmap *map, void *key);
int Hashmap_transverse(Hashmap *map, Hashmap_transverse_cb transverse_cb);
void *Hashmap_delete(Hashmap *map, void *key);

#endif