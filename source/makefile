CC = gcc
CFLAGS = -g -Wall
RMFLAGS = -rf
EXEC = vector

all: main usage

main: main.c
	$(CC) $(CFLAGS) main.c -o $(EXEC)

usage:
	@echo 'Usage of vector: valgrind ./vector'

clean:
	rm $(RMFLAGS) $(EXEC)
