CC=gcc
CFLAGS=-g -std=c11 -Werror -Werror=vla -pedantic -D_POSIX_C_SOURCE=200809L
SRCDIR=../src
TESTDIR=../test
INCDIR=../include

all: car test

car: car.o car_util.o $(SRCDIR)/main.c 
	$(CC) -I$(INCDIR) $(CFLAGS) -o $@ $^

car.o: $(SRCDIR)/car.c $(INCDIR)/car.h
	$(CC) -I$(INCDIR) $(CFLAGS) -c $<

car_util.o: $(SRCDIR)/car_util.c $(SRCDIR)/car_util.h
	$(CC) -I$(INCDIR) $(CFLAGS) -c $<

tests: car.o car_util.o $(TESTDIR)/test.c $(TESTDIR)/test_parse.c $(TESTDIR)/test_eval.c unity.o
	$(CC) -I$(INCDIR) $(CFLAGS) -o $@ $^

unity.o: $(TESTDIR)/unity.c $(TESTDIR)/unity.h $(TESTDIR)/unity_internals.h
	$(CC) -I$(INCDIR) $(CFLAGS) -c $<

.phony: clean test val

clean:
	rm car tests *.o

test: tests
	./tests

val: tests
	valgrind ./tests
