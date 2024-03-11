trees: lib.o tree.o
	gcc -o trees lib.o tree.o

tree.o:
	gcc --std=c99 --pedantic -Wall -c tree.c

lib.o:
	gcc --std=c99 --pedantic -Wall -c lib.c