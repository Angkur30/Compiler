//12.	Write a C program that will count the articles of a given string.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void countArticles(const char* str, int* aCount, int* anCount, int* theCount) {
    const char* articles[] = {"a", "an", "the"};
    char word[50];
    *aCount = *anCount = *theCount = 0;

    for (int i = 0, j = 0; ; i++) {
        if (isspace((unsigned char)str[i]) || str[i] == '\0') {
            if (j > 0) {
                word[j] = '\0';
                if (strcasecmp(word, "a") == 0) (*aCount)++;
                else if (strcasecmp(word, "an") == 0) (*anCount)++;
                else if (strcasecmp(word, "the") == 0) (*theCount)++;
                j = 0;
            }
            if (str[i] == '\0') break;
        } else {
            word[j++] = str[i];
        }
    }
}

int main() {
    char str[1000];
    int aCount, anCount, theCount;

    printf("Enter the Identifier input string/file: ");
    fgets(str, sizeof(str), stdin);

    if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';

    countArticles(str, &aCount, &anCount, &theCount);

    printf("\nOutput:\n");
    printf("Count of 'a': %d\n", aCount);
    printf("Count of 'an': %d\n", anCount);
    printf("Count of 'the': %d\n", theCount);

    return 0;
}
