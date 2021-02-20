CC=gcc
INCLUDE=include
CFLAGS=-g -std=c11 -Werror -Werror=vla -pedantic -D_POSIX_C_SOURCE=200809L

all: car test

car: car.o car_util.o src/main.c 
	$(CC) -I$(INCLUDE) $(CFLAGS) -o $@ $^

car.o: src/car.c include/car.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c $<

car_util.o: src/car_util.c src/car_util.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c $<

tests: car.o car_util.o test/test.c test/test_parse.c test/test_eval.c unity.o
	$(CC) -I$(INCLUDE) $(CFLAGS) -o $@ $^

unity.o: test/unity.c test/unity.h test/unity_internals.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c $<

.phony: clean test val

clean:
	rm car tests *.o

test: tests
	./tests

val: tests
	valgrind ./tests
