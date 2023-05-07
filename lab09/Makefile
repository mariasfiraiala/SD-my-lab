CC=gcc
CFLAGS=-Wall -Wextra -std=c99

all: bst heap

bst: bst.o
	$(CC) -o $@ $^

bst.o: bst.c
	$(CC) $(CFLAGS) -o $@ -c $<

heap: heap.o
	$(CC) -o $@ $^

heap.o: heap.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.o bst heap
