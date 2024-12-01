//Remove comments
#include<stdio.h>
#include<string.h>

int main()
{
    char str[500] = "#include <stdio.h>\nint main() {\n // This is a single-line comment\n printf(\"Hello, World!\\n\"); /* This is a\n multi-line comment */\n return 0;\n}";
    char str2[500];
    int i=0,j=0;

    while(str[i]!='\0')
    {
        if(str[i]=='/' && str[i+1]=='/')
        {
            while(str[i]!='\n')
            {
                i++;
            }
        }
        else if (str[i]=='/' && str[i+1]== '*')
        {
            i+=2;
            while(!(str[i]=='*' && str[i+1]== '/'))
            {
               if(str[i]== '\0') break;
               i++;
            }
            i+=2;
        }
        else
        {
            str2[j]=str[i];
            j++;
            i++;
        }
        
    }
    str2[j]='\0';
    
    printf("%s",str2);
    

    return 0;
}