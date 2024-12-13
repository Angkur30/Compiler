//Write a C\C++ Program that accepts a*b.
#include<stdio.h>
#include<string.h>

int main()
{
    
    char id[50];
    int i=0,flag=0;
    printf("Enter the string: \n");
    gets(id);

    int len=strlen(id);

    if(id[len-1]=='b')
    {
        flag=1;
        for(i=len-2;i>=0;i--)
        {
            if(id[i]!='a')
            {
                flag=0;
                break;
            }
        }

    }
    else
    {
        flag=0;
    }

    if(flag==1)
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Rejected\n");
    }

    return 0;
}