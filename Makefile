CC = gcc
FLAGS = -Wall -g
MAIN = arrayMemoryLeak


all: isort txtfind

valgrind:
	valgrind --leak-chek=full ./$(MAIN)

txtfind:txtfind.o
	$(CC) $(FLAGS) -o txtfind txtfind.o

txtfind.o: txtfind.c
	$(CC) $(FLAGS) -c txtfind.c

isort: isort.o
	$(CC) $(FLAGS) -o isort isort.o

isort.o: isort.c
	$(CC) $(FLAGS) -c isort.c



.PHONY: clean all

clean:
	rm txtfind isort *.o