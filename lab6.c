//Lexical Analyzer
#include<stdio.h>
#include<string.h>
#include<ctype.h>

char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", 
    "double", "else", "enum", "extern", "float", "for", "goto", "if", 
    "inline", "int", "long", "register", "restrict", "return", "short", 
    "signed", "sizeof", "static", "struct", "switch", "typedef", 
    "union", "unsigned", "void", "volatile", "while", "_Alignas", 
    "_Alignof", "_Atomic", "_Bool", "_Complex", "_Generic", "_Imaginary", 
    "_Noreturn", "_Static_assert", "_Thread_local"
};

char operators[] = "+-*/%=&|^~!<>?:.,";
char delimiters[] = ",;(){}[]#\"'";

int isDelimiter(char ch) {
    for (int i = 0; delimiters[i] != '\0'; i++) {
        if (ch == delimiters[i]) {
            return 1;
        }
    }
    return 0;
}

int isOperator(char ch) {
    for (int i = 0; operators[i] != '\0'; i++) {
        if (ch == operators[i]) {
            return 1;
        }
    }
    return 0;
}

int isKeyword(char *word) {
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isIdentifier(char *word) {
    if (!isalpha(word[0]) && word[0] != '_') {
        return 0;
    }
    for (int i = 1; word[i] != '\0'; i++) {
        if (!isalnum(word[i]) && word[i] != '_') {
            return 0;
        }
    }
    return 1;
}

int isNumber(char *word) {
    int i = 0, hasDecimal = 0;
    if (word[i] == '.' || isdigit(word[i])) {
        for (; word[i] != '\0'; i++) {
            if (word[i] == '.') {
                if (hasDecimal) return 0; 
                hasDecimal = 1;
            } else if (!isdigit(word[i])) {
                return 0; 
            }
        }
        return 1;
    }
    return 0;
}


void specify(char *str) {
    int i = 0, j = 0;
    char word[100];

    while (str[i] != '\0') {
        if (isDelimiter(str[i])) {
            if (str[i] == '\"') { 
                j = 0;
                word[j++] = str[i++];
                while (str[i] != '\0' && str[i] != '\"') {
                    word[j++] = str[i++];
                }
                if (str[i] == '\"') {
                    word[j++] = str[i++];
                }
                word[j] = '\0';
                printf("%s -> is a string literal\n", word);
            } else {
                printf("%c -> is a delimiter\n", str[i]);
                i++;
            }
        } else if (isOperator(str[i])) {
            printf("%c -> is an operator\n", str[i]);
            i++;
        } else if (isspace(str[i])) {
            i++; 
        } else {
            j = 0;
            while (str[i] != '\0' && !isspace(str[i]) && !isDelimiter(str[i]) && !isOperator(str[i])) {
                word[j++] = str[i++];
            }
            word[j] = '\0';

            if (isKeyword(word)) {
                printf("%s -> is a keyword\n", word);
            } else if (isNumber(word)) {
                printf("%s -> is a number\n", word);
            } else if (isIdentifier(word)) {
                printf("%s -> is an identifier\n", word);
            } else {
                printf("%s -> is invalid input\n", word);
            }
        }
    }
}

int main()
{
    char str[500];

    getchar(); 
    printf("Enter the input: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    specify(str); 

    return 0;
}