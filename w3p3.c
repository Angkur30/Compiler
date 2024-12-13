//Write a C program that will tokenize a string without using strtok() library function
#include<stdio.h>
#include<string.h>

int main()
{
    char str[]="These are few Sentences";
    int i=0,j=0;
    char str2[15];
    printf("%s\n",str);
    
    while(str[i]!='\0')
    {
        if(str[i]==' '||str[i]=='\n'||str[i]=='\t')
        {
            str2[j]='\0';
            printf("%s\n",str2);

            j=0;
        }
        else
        {
            str2[j]=str[i];
            j++;
        }
        i++;
    }
    str2[j]='\0';
    printf("%s\n",str2);

    return 0;
}