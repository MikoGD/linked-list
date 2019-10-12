CC=gcc
CFLAGS=-Wall -g

all: linked-list

linked-list.c:
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm *.out
