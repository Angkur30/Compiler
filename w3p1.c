#include<stdio.h>
#include<string.h>
// void modify(char *str,int len)
// {

//     char *dj="DJ AD";

//     strcpy(str,dj);
// }
int main()
{
    char str[100]="Angkur Dhar";
    char str2[100];
    int i=0,j=0;
    printf("%s\n",str);
    int len= strlen(str);
    //modify(str);
    while(str[i]!='\0')
    {
        if(str[i]==' '|| str[i]=='\n' || str[i]=='\t')
        {
            i++;
            continue;
        }

        str2[j]=str[i];

        i++;
        j++;
    }
    str2[j]='\0';
    printf("New String: \n%s\n",str2);

    return 0;
}