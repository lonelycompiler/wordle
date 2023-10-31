#include "linkedlist.h"

void insertIntoLL (struct List **LL, char *newData)
{
	// create new Node
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode->data = malloc(sizeof(char)*strlen(newData)+1);
	newNode->data = strncpy(newNode->data, newData, strlen(newData));
	newNode->data[strlen(newData)] = '\0';
	newNode->next = NULL;
	struct Node *iterator = NULL;

	// if Linked List does not exist assign head to current node
	if (!*LL)
	{
		*LL = malloc(sizeof (struct List));
		(*LL)->head = newNode;
		(*LL)->head->next = NULL;
		if (!*LL) perror("Error creating linked list within insertIntoLL()\n");
		//printf("created LL, head = %s\n", (*LL)->head->data);
	}
	else // insert temp to end of linked list
	{
		iterator = (*LL)->head;
		while (iterator->next != NULL)
		{
			iterator = iterator->next;
		}
		iterator->next = newNode;
	}
	(*LL)->size = ((*LL)->size)+1;
}

void printLinkedList (struct List **LL)
{
	if ((*LL) == NULL)
	{
		perror("List does not exist");
		return;
	}
	struct Node *temp = (*LL)->head;
	while (temp != NULL && temp->next != NULL)
	{
		printf("%s, ", temp->data);
		temp = temp->next;
	}

	if (temp != NULL && temp->next == NULL)
	{
		printf("%s\n", temp->data);
	}
}

void freeLinkedList (struct List **LL)
{
	struct Node *temp = (*LL)->head;
	while (temp != NULL)
	{
		struct Node *next = temp->next;
		free(temp->data);
		free(temp);
		temp = next;
	}
}
