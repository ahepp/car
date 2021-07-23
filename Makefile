CC=cc
CFLAGS=-g -std=c11 -Werror -Werror=vla -pedantic -D_POSIX_C_SOURCE=200809L

OBJECTS=log.o obj.o pctx.o
TEST_OBJECTS=unity.o test_obj.o

all: car test
car: car.c $(OBJECTS)
log.o: log.h
obj.o: obj.h
pctx.o: pctx.h

tests: tests.c $(OBJECTS) $(TEST_OBJECTS)
unity.o: unity/unity.c unity/unity.h unity/unity_internals.h
	$(CC) $(CFLAGS) -c unity/unity.c

.phony: clean test val
clean:
	rm *.o car tests
test: tests
	./tests
val: tests
	valgrind --leak-check=full ./tests

