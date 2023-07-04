// this one makes wordle.
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>

#include <stdlib.h>

/* Reads all of the words from the dictionary file, and stores those of the appropriate length into memory */
/*
void InitialiseWordList(void)
{
	while (fscanf(fp, “%s”, word) != EOF) {
	printf(“%s\n”, word);
	} // prints out every line in a file one by one

}
*/

int checkGreen(char word[], char guess[], int spot)
{
	if (word[spot]==guess[spot])
	{
		return 2;
	}
	
	
	return 0;
}

int checkYellow(char word[], char guess[], int spot)
{
	int i;
	for (i=0; i<5; i++)
	{
		if(guess[spot] == word[i])
		{
			return 1;
		}
	}
	
	return 0;
}

void goFindTheWord(char *stringg)
{
	int numTabs, count;
	numTabs=0;
	count=0;
	while (numTabs<2)
	{
		if (stringg[count] == '\t')
		{
			numTabs++;
		}
		count++;
	}
	printf("numTabs is %d; and count is %d. The corresponding letter is %c%c", numTabs, count, stringg[count], stringg[count+1]);
	
	int i;
	char wordd[7];
	for (i=0; i<5; i++)
	{
		wordd[i]=stringg[count+i];
	}
	for (i=0; i<5; i++)
	{
		stringg[i]=wordd[i];
	}
	wordd[5]='\0';
	
}

void getWord(char word[])
{
	// 2316 words
	FILE *fid = fopen("setlist.txt", "r");
	
	char stringg[1000];
	int num;
	num=3;//rand()%2316;
	int i;
	i=0;
	while (i<9)
	{
		word=fgets(stringg, 1000, fid);
		i++;
	}
	printf("stringg is:\n%s\n", stringg);
	printf("end of stringg\n");
	
	goFindTheWord(stringg);
	
	printf("\n we found the string\n");
	
	for (i=0; i<6; i++)
	{
		word[i] = stringg[i];
	}
	word[5]='\0';
}

int main(void)
{
	// initialise the word they gotta guess
	char word[1998];
	getWord(word);
	
	printf("\n\n~\n\n102: %s\n\n~\n\n", word);
	
	
	
	
	
	// intialise results array
	int spots[25][25]={0};
	// intialise our player's guess
	char guess[1998]="hello";
	
	
	
	
	
	
	
	
	
	
	// so we run this charade six times
	int count=0;
	int charadesRun=0;
	
	
	// run the program
	while (charadesRun <6)
	{
		// ask for a word
		
		//printf("What word do you want to guess?\n");
		scanf("%s", &guess);
		//printf("\nYou guessed:%s\n", guess);
		
		
		// then compare the word
		// first check for greens, then yellows.
		// 0 is grey, 1 is yellow, 2 is green
		
		int i, j;
		for (i=0; i<5; i++)
		{
			// set the character in the results array
			spots[charadesRun][i]=checkGreen(word, guess, i);
			
			if (spots[charadesRun][i] != 2)
			{
				// wasn't green, check if yellow
				spots[charadesRun][i]=checkYellow(word, guess, i);
			} else {
				// was green, add to the count
				count=count+1;
			}
		}
		// if we got five greens, we won and also count=5
		if (count==5)
		{
			// exit while loop
			charadesRun=7;
		} else {
			// reset
			count=0;
		}
	
		// display results
		printf("\n");
		for (i=0; i<6; i++)
		{
			for (j=0; j<5; j++)
			{
				printf("%d", spots[i][j]);
			}
			printf("\n");
		}
		
		charadesRun++;
		printf("\n\n");
	}
}