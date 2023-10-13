#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	FILE* fio;
	char *pathname = "words.txt";

	fio = fopen(pathname, "r"); // open the file
	
	// if theres an error in the file
	if (ferror(fio))
	{
		return -1;
	}
	
	char curChar;
	char *curWord = malloc(256);
	char *wordsArr[0];

	while (fgets(curWord, sizeof(curWord), fio) != NULL)
	{
		curWord[strcspn(curWord, "\n")] = 0;

		printf("%s\n", curWord);
	}
	free(curWord);
	fclose(fio); // close the file
	
	return 0;
}
