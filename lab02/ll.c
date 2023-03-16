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

ll_node_t* ll_get_nth_node_from_end(linked_list_t* list, unsigned int n)
{
	if (n > list->size) {
		n = list->size;
	}
	ll_node_t *tmp1 = list->head;
	ll_node_t *tmp2 = list->head;
	
	for (unsigned int i = 0; i < n; ++i) {
		tmp2 = tmp2 -> next;    
	}
	
	if (tmp2 == NULL) {
		return list->head->next->next;
	}
	
	while (tmp2 -> next) {
		tmp1 = tmp1 -> next;
		tmp2 = tmp2 -> next;
	}
	
	return tmp1;
}

int ll_reverse(linked_list_t *list)
{
	if (!list->head) {
		return 0;
	}
         
	ll_node_t *reversed = list->head;
	ll_node_t *tmp = list->head->next;
	
	reversed->next = NULL;
	while (tmp) {
		ll_node_t *next = tmp->next;
		ll_node_t *current = tmp;
		current->next = reversed;
		reversed = current;
		tmp = next;
	}

	list->head = reversed;
	return 0;
}

static void ll_print_int(linked_list_t *list)
{
	if (!list || !list->head) {
		return;
	}

	ll_node_t *tmp = list->head;

	while (tmp) {
		int data = *(int *) tmp->data;
		printf("%d ", data);
		tmp = tmp->next;
	}
	printf("\n");
}

static linked_list_t* create_mock_list()
{
	int x = -1;

	linked_list_t *list = malloc(sizeof(*list));
	DIE(!list, "malloc() failed\n");
	
	list->size = 0;
	list->data_size = sizeof(int);

	list->head = ll_new_node(&x, sizeof(int));
	list->size += 1;
	ll_node_t *ptr = list->head; 

	for (int i = 0; i < 10; ++i) {
		ptr->next = ll_new_node(&i, sizeof(int));
		list->size += 1;
		ptr = ptr->next;
	}

	return list;
}

static void free_mock_list(linked_list_t *list)
{
	while (list->size > 0) {
		ll_node_t* node = ll_remove_nth_node(list, 0);
		free(node->data);
		free(node);
	}
	free(list);
}

static void test_reverse() 
{
	linked_list_t *list = create_mock_list();

	printf("before reverse\n");
	ll_print_int(list);

	ll_reverse(list);

	printf("after reverse\n");
	ll_print_int(list);

	free_mock_list(list);
}

static void test_get_from_end() 
{
	ll_node_t *node;
	linked_list_t *list = create_mock_list();
	
	node = ll_get_nth_node_from_end(list, 1);
	printf("node = %d\n", *(int *) node->data);

	node = ll_get_nth_node_from_end(list, 5);
	printf("node = %d\n", *(int *) node->data);

	free_mock_list(list);
}

int main(void)
{
    printf("haha tocilare, te uiți pe lab-uri\n");

    test_reverse();
    test_get_from_end();
    return 0;
}
