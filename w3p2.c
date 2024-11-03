#include<stdio.h>
#include<string.h>

int main()
{
    char str[]="Daffodil Batch 60";

    int i=0,c=0,v=0,n=0;
    
    while(str[i]!='\0')
    {
        if(str[i]=='a' || str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
        {
            v++;
        }
        else if((str[i]>=65 && str[i]<=90)||(str[i]>97 && str[i]<=122))
        {
            c++;
        }
        else if(str[i]>=48 && str[i]<=57)
        {
            n++;
        }
        else
        {
            i++;
            continue;
        }
        i++;
    }
    printf("Vowel: %d\nConsonent: %d\nDigit:%d\n",v,c,n);

    
    return 0;
}