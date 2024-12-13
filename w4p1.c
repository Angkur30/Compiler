// Write a C program that will Remove special character from a string.
#include <stdio.h>
#include <ctype.h>

void removeSpecialCharacters(char* str) {
    int i, j = 0;
    char temp[1000]; 

    for (i = 0; str[i] != '\0'; i++) {
        if (isalnum((unsigned char)str[i])) {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0'; 

    for (i = 0; temp[i] != '\0'; i++) {
        str[i] = temp[i];
    }
    str[i] = '\0'; 
}

int main() {
    char str[1000];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    size_t len = 0;
    while (str[len] != '\0') {
        if (str[len] == '\n') {
            str[len] = '\0';
            break;
        }
        len++;
    }

    removeSpecialCharacters(str);

    printf("String after removing special characters: %s\n", str);

    return 0;
}