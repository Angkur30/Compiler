#include<stdio.h>
#include<string.h>

int main()
{
    char a[100]="Angkur";
    char b[50]=" Dhar";
    int i=0,j=0;
    
    while(a[i]!='\0')
    {
        i++;
    }

    for(j=0;b[j]!='\0';j++)
    {
        a[i]=b[j];
        i++;
    }
    a[i]='\0';
    printf("%s\n",a);

    return 0;
}