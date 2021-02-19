CC=gcc
CFLAGS=-g -std=c11 -Werror -Werror=vla -pedantic -D_POSIX_C_SOURCE=200809L

all: car test

car: main.c car.o
	$(CC) $(CFLAGS) -o $@ $^

car.o: car.c car.h
	$(CC) $(CFLAGS) -c $<

tests: test.c car.o unity.o
	$(CC) $(CFLAGS) -o $@ $^

unity.o: unity.c unity.h
	$(CC) $(CFLAGS) -c $<

.phony: clean test val

clean:
	rm car tests *.o

test: tests
	./tests

val: tests
	valgrind ./tests
