#ifndef LL_H_
#define LL_H_

#include <errno.h>

#define DIE(assertion, call_description)				\
	do {								\
		if (assertion) {					\
			fprintf(stderr, "(%s, %d): ",			\
					__FILE__, __LINE__);		\
			perror(call_description);			\
			exit(errno);				        \
		}							\
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

/*
 * @brief -> creates a new node
 * @param -> new_data = the info that we want to have in the said node
 * @param -> data_size = the size of the data that is being inserted in the node
 * @return -> the freshly created node
 */
ll_node_t *ll_new_node(const void *new_data, unsigned int data_size);

/*
 * @brief -> finds the nth node in a given list
 * @param -> list = the list in which we search for values
 * @param -> n = the index we are interested in
 * @return -> returns the node at the given index
 */
ll_node_t *ll_get_nth_node(linked_list_t *l, unsigned int n);

/*
 * @brief -> removes the nth node
 * @param -> list = the list from which we delete nodes
 * @param -> n = the index of the node that we want to be removed
 * @return -> returns the now deleted node
 */
ll_node_t *ll_remove_nth_node(linked_list_t* list, unsigned int n);

#endif
