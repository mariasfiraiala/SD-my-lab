CC = gcc
CFLAGS = -I -Wall -Wextra -std=c99

main: main.o
	$(CC) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -o $@ -c $<

debug: main.c
	$(CC) -E -dD main.c -o main.i

clean:
	rm -f *.o main main.i
