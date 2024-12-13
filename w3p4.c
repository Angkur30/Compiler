//Write a C program that will tokenize a string using strtok() library function.
#include<stdio.h>
#include<string.h>

int main()
{
    char str[]="These are few sentences";
    const char s[2]=" ";
    char *token;
    printf("%s\n",str);

    token=strtok(str,s);

    while(token!=NULL)
    {
        printf("%s\n",token);

        token=strtok(NULL,s);
    }

    return 0;
}