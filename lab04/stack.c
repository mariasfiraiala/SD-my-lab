#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

ll_node_t *ll_remove_nth_node(linked_list_t *list, unsigned int n)
{
	ll_node_t *prev, *curr;

	if (!list || !list->head)
		return NULL;

	if (n > list->size - 1)
		n = list->size - 1;

	curr = list->head;
	prev = NULL;
	while (n > 0) {
		prev = curr;
		curr = curr->next;
		--n;
	}

	if (prev == NULL) {
		list->head = curr->next;
	} else {
		prev->next = curr->next;
	}

	list->size--;

	return curr;
}

void st_pop(stack_t *st)
{
	ll_node_t *node = ll_remove_nth_node(st->list, 0);

	free(node->data);
	free(node);
}

int main(void)
{
	printf("Queue your assignments till the last night!\n");

	return 0;
}
