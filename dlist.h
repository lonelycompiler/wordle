#ifndef DLIST_H
#define DLIST_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
	char *data;
	Node *next;
};

typedef struct DList DList;
struct DList
{
	Node *head;
	Node *tail;
};

// insert new data into the DList
DList* DL_pushback (DList *LL, char *new_data);

// print the DL from head to tail
void DL_print (DList *LL);

// delete the DList
void DL_free (DList *head);

#endif
