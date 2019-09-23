CC = gcc
CPPFLAGS = -I include
CFLAGS = -Wall -fPIC

all: test.c

test.c:
	$(CC) $(CPPFLAGS) $(CFLAGS) -c src/test.c -o test
