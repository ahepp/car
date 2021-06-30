CC=cc
CFLAGS=-g -std=c11 -Werror -Werror=vla -pedantic -D_POSIX_C_SOURCE=200809L
INCDIR=../include
SRCDIR=../src
TESTDIR=../test
TPDIR=../thirdparty

all: car test

car: car.o car_util.o $(SRCDIR)/main.c 
	$(CC) -I$(INCDIR) $(CFLAGS) -o $@ $^

car.o: $(SRCDIR)/car.c $(INCDIR)/car.h
	$(CC) -I$(INCDIR) $(CFLAGS) -c $<

car_util.o: $(SRCDIR)/car_util.c $(SRCDIR)/car_util.h
	$(CC) -I$(INCDIR) $(CFLAGS) -c $<

tests: car.o car_util.o $(TESTDIR)/test.c $(TESTDIR)/test_parse.c $(TESTDIR)/test_eval.c unity.o
	$(CC) -I$(INCDIR) -I$(TPDIR)/unity $(CFLAGS) -o $@ $^

unity.o: $(TPDIR)/unity/unity.c $(TPDIR)/unity/unity.h $(TPDIR)/unity/unity_internals.h
	$(CC) -I$(INCDIR) $(CFLAGS) -c $<

.phony: clean test val

clean:
	rm car tests *.o

test: tests
	./tests

val: tests
	valgrind ./tests
