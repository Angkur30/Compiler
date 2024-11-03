// Write a C Program to Scan and Count the number of characters,
// words, and lines (input string from file).
#include<stdio.h>
#include<string.h>

int numberOfLine(char fileName[])
{
    char ch;
    FILE *fp;
    int count=1;

    fp=fopen(fileName,"r");
    if(fp!=NULL)
    {
        while((ch=fgetc(fp))!= EOF)
        {
            if(ch=='\n')
            {
                count++;
            }
        }
    }
    else
    {
        printf("File is not found!!!\n");
    }

    fclose(fp);

    return count;
}

int numberOfWord(char fileName[])
{
    char ch;
    FILE *fp;
    int count=1;

    fp=fopen(fileName,"r");
    if(fp!= NULL)
    {
        while((ch=fgetc(fp))!= EOF)
        {
            if(ch==' ' || ch=='\n' || ch=='\t')
            {
                count++;
            }
        }
    }
    else
    {
        printf("File is not found!!!!\n");
    }
    fclose(fp);
    return count;
}

int numberOfChar(char fileName[])
{
    char ch;
    FILE *fp;
    int count=0;

    fp=fopen(fileName,"r");

    if(fp!= NULL)
    {
        while((ch=fgetc(fp))!= EOF)
        {
            if(ch!=' ' && ch!= '\n')
            {
                count++;
            }
        }
    }
    else
    {
        printf("File is not found!!!!!\n");
    }
    fclose(fp);
    return count;

}

int main()
{
    char fileName[]= "data.txt";
   
   int count1= numberOfChar(fileName);

   printf("Number of Character is: %d\n",count1);

   int count2=numberOfWord(fileName);

   printf("Number of Words is: %d\n",count2);

   int count3= numberOfLine(fileName);
   printf("Number of line is: %d\n",count3);

    return 0;

}
