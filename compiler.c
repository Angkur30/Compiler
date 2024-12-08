#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

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



char stack[MAX][20];
int top = -1;

void push(char* str) {
    top++;
    snprintf(stack[top], sizeof(stack[top]), "%s", str);
}

void pop(char* str) {
    if (top >= 0) { 
        snprintf(str, sizeof(stack[top]), "%s", stack[top]);
        top--;
    }
}

void generateThreeAddressCode(char* postfix) {
    char temp[20];
    int tempVarCount = 1;
    printf("Three-Address Code:\n");
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isalnum(ch)) {
            char operand[2] = {ch, '\0'};
            push(operand);
        } else {
            char operand2[20], operand1[20];
            pop(operand2);
            pop(operand1);
            snprintf(temp, sizeof(temp), "t%d", tempVarCount++);
            printf("%s = %s %c %s\n", temp, operand1, ch, operand2);
            push(temp);
        }
    }
}

void codeGenerate() {
    char postfix[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    generateThreeAddressCode(postfix);
}

                    
//char operators[] = "+-*/%=<>", delimiters[] = ",;(){}[]";

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

int isKeyword(char* word) {
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isIdentifier(char* word) {
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

void specify(char* str) {
    int i = 0, j = 0;
    char word[50];

    while (str[i] != '\0') {
        if (isDelimiter(str[i])) {
            printf("%c -> is a delimiter\n", str[i]);
            i++;
        } else if (isOperator(str[i])) {
            printf("%c -> is a binary operator\n", str[i]);
            i++;
        } else if (str[i] == '\"') {
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
        } else if (str[i] == ' ') {
            i++;
        } else {
            j = 0;
            while (str[i] != '\0' && str[i] != ' ' && !isDelimiter(str[i]) && !isOperator(str[i]) && str[i] != '\"') {
                word[j++] = str[i++];
            }
            word[j] = '\0';
            if (isKeyword(word)) {
                printf("%s -> is a keyword\n", word);
            } else if (isIdentifier(word)) {
                printf("%s -> is an Identifier\n", word);
            } else {
                printf("%s -> is invalid input\n", word);
            }
        }
    }
}

void removeComment(const char* str, char* str2) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] == '/' && str[i + 1] == '/') {
            while (str[i] != '\n' && str[i] != '\0') {
                i++;
            }
        } else if (str[i] == '/' && str[i + 1] == '*') {
            i += 2;
            while (!(str[i] == '*' && str[i + 1] == '/')) {
                if (str[i] == '\0') break;
                i++;
            }
            i += 2;
        } else {
            str2[j++] = str[i++];
        }
    }
    str2[j] = '\0';
}

void identifierValid() {
    char str[100];
    getchar(); // Consume leftover newline
    printf("Enter the input: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    if (isKeyword(str)) {
        printf("Keyword.\n");
    } else if (isIdentifier(str)) {
        printf("Valid Identifier.\n");
    } else {
        printf("Invalid Identifier.\n");
    }
}

void demoCompiler() {
    char str[500];
    getchar(); // Consume leftover newline
    printf("Enter the input: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    char str2[500];

    removeComment(str, str2);
    specify(str2);
}

int main() {
    int a;

    while (1) {
        printf("Choose your option:\n 1. Demo compiler.\n 2. Keyword/Identifier Check.\n 3. Intermediate Code Generation.\n 0. Exit.\n");
        scanf("%d", &a);
        if (a == 1) {
            demoCompiler();
        } else if (a == 2) {
            identifierValid();
        } else if (a == 3) {
            codeGenerate();
        } else if (a == 0) {
            return 0;
        } else {
            printf("Invalid Input!!!\n");
        }
    }
}
