#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#define SIZE 8

#define DIE(assertion, call_description)                                       \
    do {                                                                       \
        if (assertion) {                                                       \
            fprintf(stderr, "(%s, %d): ", __FILE__, __LINE__);                 \
            perror(call_description);                                          \
            exit(errno);                                                       \
        }                                                                      \
    } while (0)

int **alloc_matrix(int row, int column)
{
	int **matrix = malloc(row * sizeof(*matrix));
    DIE(!matrix, "malloc() failed");
	
	for (int i = 0; i < row; ++i) {
		matrix[i] = malloc(column * sizeof(**matrix));
        DIE(!matrix[i], "malloc() failed");
	}

	return matrix;
}

void free_matrix(int row, int **matrix)
{
	for (int i = 0; i < row; ++i)
		free(matrix[i]);
	free(matrix);
}

int main(void)
{
    /*
     * Q: Where is my_matrix stored? What about *my_matrix?
     * A: my_matrix on the stack, *my_matrix on the heap.
     */
    int **my_matrix = alloc_matrix(SIZE, SIZE);

    for (int l = 0; l < SIZE; ++l) {
        for (int c = 0; c < SIZE; ++c) {
            my_matrix[l][c] = l;
            printf("%d ", my_matrix[l][c]);
        }

        printf("\n");
    }

    // sleep(3000)

    /* Q: We press CTRL+C here. What happens with the memory that hasn't been deallocated using free()?
     * A: It gets to be deallocated by the OS, at the termination of the process (when the parent calls wait()).
     */
    free_matrix(SIZE, my_matrix);
    return 0;
}
