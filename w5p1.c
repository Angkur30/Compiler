//C program that will show Syntax table (letter, digits, symbol, arithmetic/logical operator)
#include<stdio.h>

int main()
{
    char str[100]="Daffodil#@012BD+-||&&";
    char str2[4][20];
    int i=0,j=0,k=0,l=0,m=0;

    while(str[i]!='\0')
    {
        if((str[i]>=65 && str[i]<=90) || (str[i]<=122 && str[i]>=97))
        {
            str2[0][j]=str[i];
            str2[0][j+1]='\0';
            j++;
        }
        else if(str[i]<=57 && str[i]>=48)
        {
            str2[1][k]=str[i];
            str2[1][k+1]='\0';
            k++;
        }
        else if((str[i]=='&' && str[i+1]=='&')||(str[i]=='|' && str[i+1]=='|'))
        {
            str2[3][l]=str[i];
            str2[3][l+1]=str[i+1];
            str2[3][l+2]='\0';
            i++;
            l+=2;
        }
        else if(str[i]>=33 && str[i]<=47)
        {
            str2[2][m]=str[i];
            str2[2][m+1]='\0';
            m++;
        }
        i++;
    }
    for(i=0;i<4;i++)
    {
        j=0;
        printf("number %d row = ",i+1);
        while(str2[i][j]!='\0')
        {
            printf("%c",str2[i][j]);
            j++;
        }
        printf("\n");
    }

    return 0;
}