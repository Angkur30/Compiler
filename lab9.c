//Symbol Table
#include <stdio.h>
#include <string.h>

#define MAX_SYMBOLS 100
#define MAX_NAME_LEN 50
#define MAX_TYPE_LEN 20
#define MAX_SCOPE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char type[MAX_TYPE_LEN];
    char scope[MAX_SCOPE_LEN];
} Symbol;

Symbol symbolTable[MAX_SYMBOLS];
int symbolCount = 0;

void insertSymbol() {
    if (symbolCount >= MAX_SYMBOLS) {
        printf("Symbol table is full!\n");
        return;
    }

    Symbol newSymbol;
    printf("Enter identifier name: ");
    scanf("%s", newSymbol.name);
    printf("Enter data/return type: ");
    scanf("%s", newSymbol.type);
    printf("Enter scope: ");
    scanf("%s", newSymbol.scope);

    symbolTable[symbolCount++] = newSymbol;
    printf("Symbol added successfully!\n");
}

void displaySymbolTable() {
    if (symbolCount == 0) {
        printf("Symbol table is empty!\n");
        return;
    }

    printf("\nSymbol Table:\n");
    printf("Index Name                 Type                 Scope\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < symbolCount; i++) {
        printf("%5d %-20s %-20s %-20s\n", i + 1, symbolTable[i].name, symbolTable[i].type, symbolTable[i].scope);
    }
}

int main() {
    int choice;
    do {
        printf("\nSymbol Table Menu:\n");
        printf("1. Insert symbol\n");
        printf("2. Display symbol table\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertSymbol();
                break;
            case 2:
                displaySymbolTable();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
