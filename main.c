#include "linkedlist.h"
#include <time.h>
#include <limits.h>
#include <inttypes.h>
#include <stdlib.h>

struct List* getListFromFile(char *pathToFile)
{
	FILE *fio;

	fio = fopen(pathToFile, "r"); // open the file
	
	// if theres an error in the file
	if (ferror(fio))
	{
		return NULL;
	}
	
	char *curWord = malloc(256);
	struct List *LL = NULL;
	int counter = 0;

	while (fgets(curWord, sizeof(curWord), fio) != NULL)
	{
		curWord[strcspn(curWord, "\n")] = 0;
		insertIntoLL (&LL, curWord);
	}

	
	fclose(fio); // close the file
	free(curWord);
	return LL;
};

// Get a random number within the bounds of the list
uint8_t getRandNumInListBounds(uint8_t listSize)
{
	srand(time(NULL)); // seed with current time
	double randomNum = (double) rand() / INT_MAX;
	uint8_t numWithinBounds = (uint8_t) ((randomNum * 10) % (listSize + 1));
	return numWithinBounds;
}

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
	
	struct List *list = getListFromFile("words.txt");
	uint8_t randIndex = getRandNumInListBounds(list->size);
	printf("bounds = %d\n", list->size);
	printf("randIndex = %ld\n", (long) randIndex);

	//printLinkedList (&list);
	freeLinkedList(&list);

	return 0;
}
