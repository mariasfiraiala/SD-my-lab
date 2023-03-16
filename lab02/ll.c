#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ll.h"

ll_node_t* ll_new_node(const void *new_data, unsigned int data_size)
{
	ll_node_t *new_node = (ll_node_t *)malloc(sizeof(*new_node));
	DIE(!new_node, "malloc() failed\n");

	new_node->next = NULL;
	new_node->data = malloc(data_size);
	DIE(!new_node->data, "malloc() failed\n");

	memcpy(new_node->data, new_data, data_size);
	return new_node;
}

ll_node_t* ll_get_nth_node(linked_list_t *l, unsigned int n)
{
	ll_node_t *aux = l->head;
	if (n >= l->size)
		n = l->size - 1;
	for (unsigned int i = 0; i < n; ++i)
		aux = aux->next;

	return aux;
}

ll_node_t* ll_remove_nth_node(linked_list_t* list, unsigned int n)
{
	ll_node_t *node;

	if (!list || !list->size)
		return NULL;

	if (!n) {
		node = list->head;
		list->head = node->next;
	} else {
		ll_node_t *prev = ll_get_nth_node(list, n - 1);
		node = prev->next;
		prev->next = node->next;
	}

	--list->size;
	return node;
}

int main(void)
{
    printf("haha tocilare, te uiți pe lab-uri\n");

    return 0;
}
