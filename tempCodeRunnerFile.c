#include<stdio.h>
#include<string.h>

int main()
{
    char id[50];
    printf("Enter the string: \n");
    gets(id);
    int i=0,flag=1;

    while(id[i]!='\0')
    {
        if(id[i]!='a')
        {
            flag=0;
            break;
        }
        i++;
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