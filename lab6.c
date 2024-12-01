#include<stdio.h>
#include<string.h>
#include<ctype.h>

char *keywords[] = {"int", "float", "char", "double", "if", "else", "while", "for", "do",
                    "switch", "case", "break", "continue", "return", "void", "string"};
char operators[] = "+-*/%=<>", delimiters[] = ",;(){}[]";

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

int main()
{
    char str[500];
    printf("Enter the input: ");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    int i=0,j=0;
    char word[50];

    while(str[i]!='\0')
    {
        if(isDelimiter(str[i]))
        {
            printf("%c -> is a delimiter\n",str[i]);
            i++;
        }else if(isOperator(str[i]))
        {
            printf("%c -> is a binary operator\n",str[i]);
            i++;
        }else if(str[i]=='\"')
        {
            j=0;
            word[j++]= str[i++];
            while(str[i]!='\0' && str[i]!='\"')
            {
                word[j++]=str[i++];
            }
            if(str[i]=='\"')
            {
                word[j++]=str[i++];
            }
            word[j]='\0';
            printf("%s -> is a string literal\n",word);
        }else if(str[i]==' ')
        {
            i++;
        }else
        {
            j=0;
            while(str[i] != '\0' && str[i] != ' ' && !isDelimiter(str[i]) && !isOperator(str[i]) && str[i] != '\"')
            {
                word[j++]=str[i++];
            }
            word[j]= '\0';
            if(isKeyword(word))
            {
                printf("%s -> is a keyword\n",word);
            }else if(isIdentifier)
            {
                printf("%s -> is a Identifier\n",word);
            }else
            {
                printf("%s -> is invalid input\n");
            }
        }
    }

    return 0;
}