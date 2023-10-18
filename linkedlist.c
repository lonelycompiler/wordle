#include "linkedlist.h"

Node* insertToLL (Node *head, char *newData)
{
	// create new Node
	Node *newNode = malloc(sizeof(Node));
	newNode->data = newData;
	newNode->next = NULL;
	Node *iterator = NULL;

	// if Linked List does not exist assign head to current node
	if (head == NULL)
	{
		head = newNode;
	}
	else // insert temp to end of linked list
	{
		iterator = head;
		while (iterator->next != NULL)
		{
			iterator = iterator->next;
		}
		iterator->next = newNode;
	}
	return head;
}

void printLinkedList (Node *head)
{
	Node *temp = head;
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

void freeLinkedList (Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		Node *next = temp->next;
		free(temp);
		temp = next;
	}
}
