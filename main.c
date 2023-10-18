#include "linkedlist.h"

int main (int argc, char *argv[])
{
	// *char[] words <- file containing words on each new line
	// pick random word from words array
	// ask player for input
	// give result
	// if player has all G: they win
	// if they don't have all letters correct,
		// if they don't have any tries left: they lose
		// if they have tries left: go to asking player for input
	FILE *fio;
	char *pathname = "words.txt";

	fio = fopen(pathname, "r"); // open the file
	
	// if theres an error in the file
	if (ferror(fio))
	{
		return -1;
	}
	
	char *curWord = malloc(256);
	Node *head = NULL;
	int counter = 0;
	while (fgets(curWord, sizeof(curWord), fio) != NULL)
	{
		curWord[strcspn(curWord, "\n")] = 0;

		head = insertToLL (head, curWord);
		if (++counter == 5) break;
	}
	printLinkedList (head);
	free(curWord);
	fclose(fio); // close the file
	freeLinkedList(head);
	
	return 0;
}
