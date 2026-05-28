CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRC = src/entity.c src/list.c src/main.c

all:
	$(CC) $(CFLAGS) $(SRC) -o main.bin

test:
	$(CC) $(CFLAGS) test/test.c src/entity.c src/list.c -o test.bin
	./test.bin

clean:
	rm -f main.bin test.bin
	