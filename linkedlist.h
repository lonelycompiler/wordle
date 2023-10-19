#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
	char *data;
	struct Node *next;
};

struct List
{
	struct Node *head;
	int size;
};

// insert new data into the linked list
void insertIntoLL (struct List **LL, char *newData);

// print the linked list
void printLinkedList (struct List **LL);

// delete the linkedlist
void freeLinkedList (struct List **LL);

#endif
