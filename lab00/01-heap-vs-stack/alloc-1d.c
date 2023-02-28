#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/*
 * Q: What does SIZE represent?
 * A: A macro.
 *
 * Q: Where do we usually place macros?
 * A: Inside headers (NOT IN LIBRARIES!!!).
 *
 * Q: What other things do headers also contain?
 * A: Function signatures, type definitions (typedefs).
 */

#define SIZE 1024

#define DIE(assertion, call_description)                                       \
    do {                                                                       \
        if (assertion) {                                                       \
            fprintf(stderr, "(%s, %d): ", __FILE__, __LINE__);                 \
            perror(call_description);                                          \
            exit(errno);                                                       \
        }                                                                      \
    } while (0)


int main(void)
{
    /* 
     * Q: Why do we prefer sizeof(*v) instead of sizeof(int)?
     * A: For genericity and consistency
     *
     * Q: What's the size of v? What about *v?
     * A: Depends on the architecture (usually the pointer gets the size of the processor word)
     */
    int *v = malloc(SIZE * sizeof(*v));
    DIE(!v, "malloc() failed");

    for (int i = 0; i < SIZE; ++i) {
        v[i] = i;
        printf("%d ", v[i]);
    }

    free(v);
    return 0;
}
