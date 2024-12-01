#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    printf("Enter the input: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; 

    int kFlag = 0, Flag = 1;
    char *keywords[] = {
        "auto", "break", "case", "char", "continue", "do", "default", "const",
        "double", "else", "enum", "extern", "for", "if", "goto", "float",
        "int", "long", "register", "return", "signed", "static", "sizeof",
        "short", "struct", "switch", "typedef", "union", "void", "while",
        "volatile", "unsigned"
    };

    
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(str, keywords[i]) == 0) {
            kFlag = 1;
            break;
        }
    }

    if (kFlag == 1) {
        printf("Keyword\n");
    } else {
        
        if (isalpha(str[0]) || str[0] == '_') {
            for (int i = 1; str[i] != '\0'; i++) {
                if (!isalnum(str[i]) && str[i] != '_') {
                    Flag = 0;
                    break;
                }
            }
            if (Flag == 1) {
                printf("Valid Identifier\n");
            } else {
                printf("Invalid Identifier\n");
            }
        } else {
            printf("Invalid Identifier\n");
        }
    }

    return 0;
}