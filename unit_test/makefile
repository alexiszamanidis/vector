CC = gcc
CFLAGS = -g -Wall
RMFLAGS = -rf
EXEC = test
OBJS = test.o
CUNIT = -lcunit

all: main usage

main: $(OBJS) main.c
	$(CC) $(CFLAGS) $(OBJS) main.c $(CUNIT) -o $(EXEC)

test.o: test.c
		$(CC) $(CFLAGS) $(CUNIT) -c test.c

usage:
	@echo 'Usage of test: valgrind ./test'

clean:
	rm $(RMFLAGS) $(EXEC) $(OBJS)
