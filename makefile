CC = cc
CFLAGS = -Wall -Wextra -g -Iinclude


SRC1 = test/test1.c src/tas_spinlock.c
OBJ1 = $(SRC1:.c=.o)

SRC2 = test/test2.c src/cas_spinlock.c
OBJ2 = $(SRC2:.c=.o)

SRC3 = test/test3.c src/cas_semaphore.c
OBJ3 = $(SRC3:.c=.o)

test1: $(OBJ1)
	$(CC) $(OBJ1) -o bin/test1

test2: $(OBJ2)
	$(CC) $(OBJ2) -o bin/test2

test3: $(OBJ3)
	$(CC) $(OBJ3) -o bin/test3


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ1) $(OBJ2) $(OBJ3) bin/test1 bin/test2 bin/test3

run_test1: test1
	bin/test1

run_test2: test2
	bin/test2

run_test3: test3
	bin/test3

check: test1 test2 test3
	bin/test1
	bin/test2
	bin/test3