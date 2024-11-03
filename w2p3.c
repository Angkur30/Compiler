//Write a C\C++ Program that accepts a*b (read input from file).
#include<stdio.h>
#include<string.h>

int valid(char str[])
{
    int i,flag=0;
    int len= strlen(str);
    i=len-2;
    if(str[len-1]=='b')
    {
        flag=1;
        while(i>=0)
        {
            if(str[i]!='a')
            {
                flag=0;
                break;
            }
            i--;
        }
    }
    else
    {
        flag=0;
    }

    return flag;
}

int main()
{
    char str[100];
    char fileName[]="data2.txt";
    char ch;
    int i=0;
    FILE *fp;

    fp=fopen(fileName,"r");

    while((ch=fgetc(fp))!=EOF)
    {
        str[i]=ch;
        i++;
    }
    fclose(fp);
    str[i]='\0';
    printf("%s\n",str);

    int flag=valid(str);

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