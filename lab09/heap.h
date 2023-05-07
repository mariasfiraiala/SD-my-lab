#ifndef __HEAP_H__
#define __HEAP_H__

#define GO_UP(x)		(((x) - 1) >> 1)
#define GO_LEFT(x)		(((x) << 1) + 1)
#define GO_RIGHT(x)		(((x) << 1) + 2)

typedef struct team_t team_t;
struct team_t {
	char *name;
	int score;
};

typedef struct heap_t heap_t;
struct heap_t {
	/* heap elements */
	team_t **arr;

	int size;
	int capacity;

	/* function used for sorting the keys */
	int (*cmp)(const team_t *key1, const team_t *key2);
};

#endif
