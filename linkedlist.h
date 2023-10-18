#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
	char *data;
	Node *next;
};

// insert new data into the linked list
Node* insertToLL (Node *head, char *new_data);

// print the linked list
void printLinkedList (Node *head);

// delete the linkedlist
void freeLinkedList (Node *head);

#endif
