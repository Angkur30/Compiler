// Three address code
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
    stack<char> stack;
    int i=0,j=0,k=1;
    char str2[10][10];
    char str[]="abc*+";

    while(str[i] != '\0')
    {
        if(str[i]== '+' || str[i] == '-' || str[i] == '*' || str[i]== '/')
        {
            str2[j][0]='t';
            str2[j][1]=k+'0';
            str2[j][2]= '=';
            str2[j][3]= stack.top();
            stack.pop();
            str2[j][4]=str[i];
            str2[j][5]=stack.top();
            stack.pop();
            str2[j][6]= '\0';

            for(int l=0; str2[j][l] !='\0';l++)
            {
                cout<<str2[j][l];
            }
            cout<< "\n";

            stack.push(str2[j][0]);
            i++;
            j++;
            k++;
        }
        else
        {
            stack.push(str[i]);
            i++;
        }
    }
    cout<<"Original Expression: "<<str<<endl;


    return 0;
}