#include "dlist.h"


DList* DL_pushback (DList *LL, char *new_data)
{
	// create new Node
	Node *temp = (Node *) malloc(sizeof(Node));
	temp->data = new_data;

	// if DList is not created yet
	if (LL == NULL)
	{
		// create DList
		LL = (DList *) malloc(sizeof(DList));

		// populate DList, new_data goes into head
		LL->head = &temp;
		LL->tail = &temp;
	}
	else
	{
		//Node *tail = LL->tail;
		LL->tail->next = temp;
		temp->prev = LL->tail;
		LL->tail = &temp;
	}
	return LL;
}

void DL_print (DList *LL)
{
	Node *temp = *LL->head;
	while (temp != LL->tail)
	{
		printf("%s, ", temp->data);
		temp = temp->next;
	}

	if (LL->tail != NULL)
	{
		printf("%s\n", temp->data);
	}
}

void DL_free (DList *LL)
{

}

//DList* DL_indexOf (DList *head, char *targetData);
