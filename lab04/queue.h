#ifndef Q_H_
#define Q_H_

#include <errno.h>

#define DIE(assertion, call_description)                                       \
	do {                                                                       \
		if (assertion) {                                                       \
			fprintf(stderr, "(%s, %d): ", __FILE__, __LINE__);                 \
			perror(call_description);                                          \
			exit(errno);                                                       \
		}                                                                      \
	} while (0)

typedef struct queue_t
{
	/* queue maximum size, its capacity */
	unsigned int max_size;
	/* how many elements are stored at the moment */
	unsigned int size;
	/* number of bytes of the stored data type */
	unsigned int data_size;
	/* index where the front() and deque() operations take place */
	unsigned int read_idx;
	/* index where the enque() operation takes place */
	unsigned int write_idx;
	/* buffer that stores the elements of the queue */
	void **buff;
} queue_t;

int q_dequeue(queue_t *q);

#endif
