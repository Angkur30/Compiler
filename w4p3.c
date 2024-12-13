//C program that will take multiple lines as input and identify the comments if there any.
#include <stdio.h>
#include <string.h>

void findComments(const char* str) {
    const char* singleLineStart = "//";
    const char* multiLineStart = "/*";
    const char* multiLineEnd = "*/";

    const char* ptr = str;

    while (*ptr != '\0') {
        // Check for single-line comments
        if (strncmp(ptr, singleLineStart, 2) == 0) {
            const char* end = strchr(ptr, '\n');
            printf("Single-line comment: ");
            if (end) {
                while (ptr < end) {
                    putchar(*ptr++);
                }
            } else {
                printf("%s", ptr);
                break;
            }
            printf("\n");
        } 
        // Check for multi-line comments
        else if (strncmp(ptr, multiLineStart, 2) == 0) {
            const char* end = strstr(ptr, multiLineEnd);
            printf("Multi-line comment: ");
            if (end) {
                while (ptr <= end + 1) {
                    putchar(*ptr++);
                }
            } else {
                printf("%s", ptr);
                break;
            }
            printf("\n");
        } else {
            ptr++;
        }
    }
}

int main() {
    const char str[] = "// This is a single-line comment\nprintf(\"Hello World\"); /* This is a multi-line comment */";

    findComments(str);

    return 0;
}
