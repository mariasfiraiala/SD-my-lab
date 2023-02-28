#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define DIE(assertion, call_description)                                       \
    do {                                                                       \
        if (assertion) {                                                       \
            fprintf(stderr, "(%s, %d): ", __FILE__, __LINE__);                 \
            perror(call_description);                                          \
            exit(errno);                                                       \
        }                                                                      \
    } while (0)
 
void sort_vector(int n, void *v, int elem_size, int (*compare_function)(void *, void *))
{
 
    char *tmp = malloc(elem_size);
    DIE(!tmp, "malloc() failed");
 
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; j++) {
            void *vi = (char *)v + i * elem_size; // &v[i]
            void *vj = (char *)v + j * elem_size; // &v[j]
            if (compare_function(vi, vj) > 0) {
                memcpy(tmp, vj, elem_size); // tmp = v[j];
                memcpy(vj, vi, elem_size); // v[j] = v[i];
                memcpy(vi, tmp, elem_size); // v[i] = tmp;
            }
        }
    }
 
    free(tmp);
}
 
/* this function will only be used for comparing integers */
int compare_ints(void *ptr_a, void *ptr_b) {
    /*
     * here we know that ptr_a and ptr_b ar pointer to addreses where we have ints stored
     * so it's safe to cast and dereference, in order to get the int value
     */
    int a = *(int *) ptr_a; // get first value - a
    int b = *(int *) ptr_b; // get second value - b
    return a > b;
}
 
/* this function will only be used for comparing doubles */
int compare_doubles(void *ptr_a, void *ptr_b) {
    /*
     * here we know that ptr_a and ptr_b ar pointer to addreses where we have doubles stored
     * so it's safe to cast and dereference, in order to get the double value
     */
    double a = *(double *) ptr_a; // get first value - a
    double b = *(double *) ptr_b; // get second value - b
    return a > b;
}
 
/* this function will only be used for comparing strings */
int compare_strings(void *ptr_a, void *ptr_b) {
    /*
     * here we know that ptr_a and ptr_b ar pointer to addreses where we have char* stored
     * so it's safe to cast and dereference, in order to get the char* value
     */
    char *a = *(char **) ptr_a; // get first value - a
    char *b = *(char **) ptr_b; // get second value - b
    return strcmp(a, b);
}
 
int main(void)
{
    int v[] = {2, 10, -3, 7};
    int size_v = sizeof(v) / sizeof(v[0]);
    sort_vector(size_v, v, sizeof(int), compare_ints);
    for (int i = 0; i < size_v; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
 
    double w[] = {2.3, 10.3, -3.04, 7.02};
    int size_w = sizeof(w) / sizeof(w[0]);
    sort_vector(size_w, w, sizeof(double), compare_doubles);
    for (int i = 0; i < size_w; ++i) {
        printf("%lf ", w[i]);
    }
    printf("\n");
 
    char *z[] = {"this", "is", "an", "example"};
    int size_z = sizeof(z) / sizeof(z[0]);
    sort_vector(size_z, z, sizeof(char *), compare_strings);
    for (int i = 0; i < size_z; ++i) {
        printf("%s ", z[i]);
    }
    printf("\n");
 
    return 0;
}
