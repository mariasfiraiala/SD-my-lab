CC=gcc
CFLAGS=-Wall -Wextra -std=c99

all: queue stack

queue: queue.o
	$(CC) -o $@ $^

queue.o: queue.c
	$(CC) $(CFLAGS) -o $@ -c $<

stack: stack.o
	$(CC) -o $@ $^

stack.o: stack.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.o queue stack
