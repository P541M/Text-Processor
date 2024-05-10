#include "functionHeaders.h"

int main(int argc, char *argv[]) {
    // Variables for function 1.
    char fileName[SIZE];

    // Variables for function 2.
    int tempNumWords = 0;
    int tempNumSentences = 0;
    int *numWords = &tempNumWords;
    int *numSentences = &tempNumSentences;

    // Variables for function 3.
    char temp[] = "Psalm";

    // Variables for function 4.
    char **testArrTwo;

    // Variables for function 5.
    // N/A

    // Variables for function 6.
    int wordPosition = 0;
    char suffixAddON[SIZE];
    char stringTwo[SIZE];

    // Function call 1.
    strcpy(fileName, argv[1]);
    char *stringReturn = readFile(fileName);

    // Function call 2.
    dejaVu(stringReturn, numWords, numSentences);
    printf("\nFunction 2:\n-----------\n%d %d\n", *numWords, *numSentences);

    // Function call 3.
    printf("\nFunction 3:\n-----------\n");
    char *stringReturnTwo = goBig(temp);

    // Function call 4.
    printf("\nFuction 4:\n-----------\n");
    testArrTwo = malloc(*numWords * sizeof(char *));
    testArrTwo = goAway(stringReturn, numWords);

    // Function call 5.
    printf("\n\nFuction 5:\n-----------\n");
    char *stringReturnThree = breathless(stringReturn);

    // Function call 6.
    printf("\nFunction 6:\n-----------\n");

    printf("Enter in position: ");
    scanf(" %d", &wordPosition);

    printf("Enter suffix: ");
    scanf(" %s", suffixAddON);

    printf("\n");

    tail(stringReturn, wordPosition, suffixAddON);

    return 0;
}
