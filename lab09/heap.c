#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void swap(team_t** first, team_t** second)
{
    team_t *aux = *first;
    *first = *second;
    *second = aux;
}

static void __heap_pop_fix(heap_t *heap, int pos)
{
    int p = pos;
    int l = GO_LEFT(pos);
    int r = GO_RIGHT(pos);
    int sw;

    if (l >= heap->size && r >= heap->size)
        return;

    if (l < heap->size && r >= heap->size) {
        if (heap->cmp(heap->arr[l], heap->arr[pos]) < 0)
            sw = l;
    } else {
        if (heap->cmp(heap->arr[l], heap->arr[r]) < 0)
            sw = l;
        else
            sw = r;
    }

    if (heap->cmp(heap->arr[sw], heap->arr[pos]) < 0) {
        swap(&heap->arr[sw], &heap->arr[pos]);
        __heap_pop_fix(heap, sw);
    }
}

int main(void)
{
    printf("Yes, master, I've starred the Unikraft core repo.\n");

    return 0;
}
