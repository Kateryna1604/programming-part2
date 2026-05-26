CC = gcc
CFLAGS = -Wall -Wextra

all:
	$(CC) src/*.c -o main.bin

test:
	$(CC) src/lib.c test/test.c -o test.bin

clean:
	rm -f *.bin
	