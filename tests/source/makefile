CC = gcc
CFLAGS = -g -Wall
RMFLAGS = -rf
EXEC = main
OBJS = test.o
CUNIT = -lcunit

all: main usage

main: $(OBJS) main.c
	$(CC) $(CFLAGS) $(OBJS) main.c $(CUNIT) -o main
	rm $(RMFLAGS) $(OBJS)

test.o: test.c
		$(CC) $(CFLAGS) $(CUNIT) -c test.c

usage:
	@echo 'Usage of test: valgrind ./main'

clean:
	rm $(RMFLAGS) $(EXEC) $(OBJS)
