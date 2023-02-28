#include <stdio.h>

int main(void)
{
    int val = 16;
    int *p = &val;
    int **q = &p;

    printf("p\tcontains: %p\n", p); // address of val
    printf("*p\tcontains: %d\n", *p); // value of val
    printf("q\tcontains: %p\n", q); // address of p
    printf("*q\tcontains: %p\n", *q); // address of val
    printf("**q\tcontains: %d\n", **q); // value of val
}
