all: main dlist
	gcc dlist.o main.o -g -o a.out

main: main.c
	gcc -c main.c -g

dlist: dlist.c
	gcc -c dlist.c -g
