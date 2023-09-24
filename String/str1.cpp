#include <bits/stdc++.h>
using namespace std;

void replaceCharacter(char ch[] , int len){

    int index = 0;

    while(ch[index]!='\0')
    {
        if(ch[index]=='@')
        {
            ch[index] = ' ';
            index++;
        }
        else{
            index++;
        }
    }
}

int main()
{
   char ch[100];

    cout<<"Enter the paragraph"<<endl;
    cin.getline(ch , 100);
    int len = strlen(ch);

    replaceCharacter(ch ,len );

    cout<<"the sentence after replacement of space with @ is:-"<<"  "<<ch;

   return 0;
}