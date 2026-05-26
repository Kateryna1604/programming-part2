CC = clang

CFLAGS = -Wall -Wextra -Werror -std=c11

SRC = src/main.c src/lib.c

OUT = dist/lab13.bin

all: clean prep compile

prep:
	mkdir -p dist

compile:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run:
	./$(OUT)

clean:
	rm -rf dist
	