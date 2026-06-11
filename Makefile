CC=gcc
CFLAGS=-Wall -Wextra -std=c11

all:
	$(CC) main.c -o taskmanager $(CFLAGS)

run:
	./taskmanager

clean:
	rm -f taskmanager
