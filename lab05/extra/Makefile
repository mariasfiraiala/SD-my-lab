CC=gcc
CFLAGS=-Wall -Wextra -std=c99

all: qsort my-qsort

qsort: qsort.o
	$(CC) -o $@ $^

qsort.o: qsort.c
	$(CC) $(CFLAGS) -o $@ -c $<

my-qsort: my-qsort.o
	$(CC) -o $@ $^

my-qsort.o: my-qsort.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.o qsort my-qsort
