#include<stdio.h>
#include<string.h>

int numberOfLine(char a[])
{
    int i=0,count=0;

    while (a[i] != '\0')
    {
        if(a[i] == '\n')
        {
            count++;
        }
        i++;
    }
    if(i>0 && a[i-1] != '\n')
    {
        count++;
    }

    return count;
}

int numberOfWord(char a[])
{
    int i=0,count=1;

    while(a[i]!='\0')
    {
        if(a[i]==' ' || a[i]=='\n' || a[i]=='\t')
        {
            count++;
        }
        i++;
    }

    return count;
}

int numberOfChar(char a[]){
    int i=0,count=0;

    while(a[i]!='\0')
    {
        if(a[i]!=' ')
        {
            count++;
        }
        i++;
    }
    return count;
}

int main()
{
    char str[50];
    gets(str);
    //char str[100]="Hello, World!\nThis is a test.\nCounting lines in this string.";


    printf("%s\n",str);

    int count= numberOfChar(str);
    printf("Number of Character: %d\n",count);

    int count2= numberOfWord(str);
    printf("Number of Words: %d\n",count2);

    int count3= numberOfLine(str);
    printf("Number of Lines: %d\n",count3);

    return 0;
}