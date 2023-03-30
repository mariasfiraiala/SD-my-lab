#ifndef S_H_
#define S_H_

#include <errno.h>

#define DIE(assertion, call_description)                                       \
	do {                                                                       \
		if (assertion) {                                                       \
			fprintf(stderr, "(%s, %d): ", __FILE__, __LINE__);                 \
			perror(call_description);                                          \
			exit(errno);                                                       \
		}                                                                      \
	} while (0)

typedef struct ll_node_t
{
	void* data;
	struct ll_node_t* next;
} ll_node_t;

typedef struct linked_list_t
{
	ll_node_t* head;
	unsigned int data_size;
	unsigned int size;
} linked_list_t;

typedef struct stack_t
{
	struct linked_list_t *list;
} stack_t;

ll_node_t *ll_remove_nth_node(linked_list_t *list, unsigned int n);

void st_pop(stack_t *st);

#endif