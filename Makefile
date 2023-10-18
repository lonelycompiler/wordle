all: main linkedlist
	gcc linkedlist.o main.o -g -o a.out

main: main.c
	gcc -c main.c -g

linkedlist: linkedlist.c
	gcc -c linkedlist.c -g

clean:
	rm *.o
	rm a.out
