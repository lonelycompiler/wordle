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
	char *curWord = "";
	char *temp;
	char *wordsArr[0];
	while((curChar = fgetc(fio)) != EOF)
	{
		// if its a new line, put word into array and
		// reset word
		if (curChar == '\n')
		{
			printf("%s\n", curWord);
			curWord = "";
			continue;
		}
		// put character into word if its not a new line
		// extra room for word
		temp = malloc(strlen(curWord) + 1);
		temp = strncpy(temp, curWord, strlen(curWord));
		temp[strlen(curWord)] = curChar;

		curWord	= (char *) malloc(strlen(temp)+1);
		curWord = strcpy(curWord,temp);
		curWord[strlen(temp)] = '\0';
	}
	free(temp);
	fclose(fio); // close the file
	
	return 0;
}
