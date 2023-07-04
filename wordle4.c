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

/*
void getWord(char word[])
{
	FILE    *textfile;
    char    ch;
     
    textfile = fopen("setlist.txt", "r");

	int numTabs=-2;
	int doWeReadQ=0;
	int count=0;
    while ((ch = fgetc(textfile))!=EOF)7```8``8`3=--5555555555555555555555555555555555555555555555555555555555555555543444333333333333333333333333
	{
		putchar(ch);
		if (ch == '\t')
		{
			printf("AAA");
			numTabs++;
			if (numTabs==2)
			{
				// we now read the next five letters to a file
				doWeReadQ=1;
			}
			
			if (doWeReadQ == 1)
			{
				word[count] = ch;
				count++;
				if (count==5)
				{
					// finished reading
					doWeReadQ=0;
					count=0;
					numTabs=0;
					word[5]='\0';
					printf("\nand the word we got was %s\n", word);
				}
			}
		}
	}
	
    fclose(textfile);
}
*/

// this one gets a word at a time
void getWord()
{
	int i=0;
	
	FILE *fp;
	fp=fopen("setlist.txt", "r");
	//rread text; wwrite text; “a”append text. Add a b for binary (e.g., .bmp)
	// If it fails, fp==NULL is true.
	// continuing:
	char word[100];
	fscanf(fp, "%s", word); // prints out the first word
	printf("line 102\n");
	// returns EOF when you reach End Of File

	while ((fscanf(fp, "%s", word) != EOF) && (i<15))
	{
		printf("the word is %s\t\t\tand i is %d\n", word, i);
		i++;
	}
} 


int main(void)
{
	// initialise the word they gotta guess
	char word[1998]="abcde";
	
	// intialise results array
	int spots[25][25]={0};
	// intialise our player's guess
	char guess[1998]="hello";
	
	getWord(word);
	
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