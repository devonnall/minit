CFLAGS=-Wall -Wextra -O2 -Iinclude
CC=clang

SRCS=src/main.c src/add.c src/v_char.c

all: build

build: src/main.c
	$(CC) $(CFLAGS) -o build/main $(SRCS)