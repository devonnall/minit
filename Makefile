CFLAGS=-Wall -Wextra -O2 -Iinclude -I$(shell brew --prefix openssl)/include
LDFLAGS=-L$(shell brew --prefix openssl)/lib -lssl -lcrypto
CC=clang

SRCS=$(wildcard src/*.c)
TST_SRCS=$(filter-out src/main.c, $(SRCS)) $(wildcard test/*.c)

TST_CFLAGS=-Wall -Wextra -Iinclude -Itest -I$(shell brew --prefix openssl)/include

all: build

build: src/main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o bin/main $(SRCS)

test: test/test_all.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o bin/test $(TST_SRCS) 
