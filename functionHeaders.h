#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

char* readFile(char* filename);

void dejaVu(char* aString, int* numWords, int* numSentences);

char* goBig(char* aString);

char** goAway(char* aString, int* numWordsReturned);

char* breathless(char* aString);

void tail(char* aString, int whichWord, char* desiredSuffix);
