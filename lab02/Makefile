CC=gcc
CFLAGS=-I -Wall -Wextra -std=c99

ll: ll.o
	$(CC) -o $@ $^

ll.o: ll.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.o ll
