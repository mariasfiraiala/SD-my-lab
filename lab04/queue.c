#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int q_dequeue(queue_t *q)
{
	if (!q->size)
		return 0;

	free(q->buff[q->read_idx]);
	++q->read_idx;

	q->read_idx %= q->max_size;
	--q->size;

	return 1;
}

int main(void)
{
	printf("Stop peeking and do your homework!\n");

	return 0;
}
