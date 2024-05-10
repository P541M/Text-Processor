#include "functionHeaders.h"

// Function 1
char *readFile(char *filename) {
    // Opens the file for reading.
    FILE *filePtr = fopen(filename, "r");

    // If statement to verify if the file is able to be opened.
    if (filePtr == NULL) {
        printf("Error: Not able to open file.\n");
        return 0;
    }

    // i = 1 so that the array is not empty.
    int i = 1;

    // Allocates memory for the string.
    char *stringArray = malloc(sizeof(char));

    // Temporarily holds the character to be "looked at".
    char charHolder = '\0';

    // While loop to iterate through the file.
    while (!feof(filePtr)) {
        // Reads through the file and stores it in "charHolder".
        charHolder = fgetc(filePtr);

        // If statement to check if it has hit the EOF (end of file).
        if (charHolder != EOF) {
            // Adds the character to the string.
            stringArray[i - 1] = charHolder;

            // Increments the string length.
            i++;

            // Resizes the memory allocation depending the string length.
            stringArray = realloc(stringArray, sizeof(char) * i);
        }
    }

    // Closes the file.
    fclose(filePtr);

    // Returns the string containing whatever the file holds.
    return stringArray;
}

// Funtion 2
void dejaVu(char *aString, int *numWords, int *numSentences) {
    // Finds the length of "aString".
    int charNum = strlen(aString);

    // Stores the amount of sentences and words
    int wordHolder = 0;
    int sentenceHolder = 0;

    // For loop to go through each character in the string
    for (int i = 0; i < charNum; i++) {
        // Checks if the next line as a ' ' or a new line.
        if (aString[i] == ' ' || aString[i] == '\n') {
            if (i > 0 && aString[i - 1] != ' ' && aString[i - 1] != '\n') {
                // If it is not a space or a new line, increment "wordHolder".
                wordHolder++;
            }
        }
        // Checks if it is a '.', '!', '?' and a ';'
        else if (aString[i] == '.' || aString[i] == '!' || aString[i] == '?' || aString[i] == ';' ||
                 aString[i] == ':') {
            if (i > 0 && aString[i - 1] != aString[i]) {
                // Increment if the previous character is not the same.
                sentenceHolder++;
            }
        }
    }

    // Stores the word count and sentence count.
    *numWords = wordHolder;
    *numSentences = sentenceHolder;
}

// //Function 3
char *goBig(char *aString) {
    // Counters for future loops and incrementors.
    int i = 0;
    int j = 0;
    int k = 0;
    int choice[strlen(aString)];

    // Makes memory for "newStr".
    char *newStr = malloc(strlen(aString) * sizeof(char));

    // For loop that prompts the user.
    for (i = 0; i < strlen(aString); i++) {
        printf("Enter Value: ");
        scanf("%d", &choice[i]);

        // Makes sure the user input is a non negative.
        if (choice[i] < 1) {
            free(newStr);
            return NULL;
        }
    }

    // For loop that applies the users input to the given string.
    for (i = 0; i < strlen(aString); i++) {
        for (j = 0; j < choice[i]; j++) {
            newStr[k++] = aString[i];
        }
    }

    // Prints the string.
    printf("%s\n", newStr);

    // Returns the string.
    return newStr;
}

// Function 4
char **goAway(char *aString, int *numWordsReturned) {
    // Gets the length of the given string.
    int numChar = strlen(aString);
    int numWords = 1;

    // Incrementors.
    int i;
    int j = 0;
    int k = 1;
    int x;

    char **wordArr;

    // For loop to count the number of words in the given string.
    for (x = 0; x < numChar; x++) {
        if (aString[x] == ' ' || aString[x] == '\n') {
            if (x > 0 && (aString[x - 1] == ' ' || aString[x - 1] == '\n')) {
                continue;
            }
            // Increments the numnber of words.
            numWords++;
        }
    }

    // Allocates memory for the strings.
    wordArr = malloc(sizeof(char *) * numWords);

    // Allocates memory for each string.
    for (x = 0; x < numWords; x++) {
        wordArr[x] = malloc(sizeof(char) * 2);
    }

    // For loop to look through the strings.
    for (i = 0; i < numChar; i++) {
        // If statement to check if space or newline.
        if (aString[i] == ' ' || aString[i] == '\n') {
            // Skips the character.
            if (i > 0 && (aString[i - 1] == ' ' || aString[i - 1] == '\n')) {
                continue;
            }
            // Increments to the next word.
            j++;
            // Resets the character.
            k = 1;
        } else {
            // Adds the character to the word.
            wordArr[j][k - 1] = aString[i];
            printf("%c", wordArr[j][k - 1]);
            // Increments the character index.
            k++;
            wordArr[j] = realloc(wordArr[j], sizeof(char) * (k));
        }
    }

    *numWordsReturned = numWords;
    // Returns the array of strings.
    return wordArr;
}

// Function 5
char *breathless(char *aString) {
    // Gets the length of aString and saves it to "stringLength".
    int stringLength = strlen(aString);

    // For loop to go through the string.
    for (int i = 0; i < stringLength; i++) {
        // If statement to check if any of the items in the array are equal to the given.
        if (aString[i] == '.' || aString[i] == ':' || aString[i] == ';' || aString[i] == '?' || aString[i] == '!') {
            // For loop to shift all characters to the left by one position.
            for (int j = i; j < stringLength; j++) {
                // Stores the given string in aString.
                aString[j] = aString[j + 1];
            }
            // This will take the previous space.
            stringLength--;
            // This will fill in the previous space.
            i--;
        }
    }

    // Prints the string.
    printf("%s", aString);
    return aString;
}

// Function 6
void tail(char *aString, int whichWord, char *desiredSuffix) {
    // Variable for the word position.
    int wordPosition = 0;

    // goAway is used to split the string into words and determine position.
    char **arr = goAway(aString, &wordPosition);

    // Gets the word at the specific index.
    char *temp = arr[whichWord - 1];

    // For loop to go through the characters of the word.
    for (int i = 0; temp[i] != '\0'; i++) {
        // Prints the word
        printf("\n%c%s\n", temp[i], desiredSuffix);
    }
}