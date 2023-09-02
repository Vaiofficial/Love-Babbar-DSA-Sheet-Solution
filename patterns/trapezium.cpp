#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n =5;

   for(int row = 0; row<n;row++)
   {
    //printing left side stars

    for(int star=0;star<n-row;star++)
    {
        cout<<"*";
    }
    //printting triangle spaces

    for (int space = 0; space < 2*row+1; space++)
    {
        cout<<" ";
    }

    //printing right side stars

    for (int star = 0; star < n-row; star++)
    {
        cout<<"*";
    }

    cout<<endl;
   }
    
    //printing bottom side of the pattern

   for(int row = 0; row<n;row++)
   {
    //printing left side stars

    for(int star=0;star<row+1;star++)
    {
        cout<<"*";
    }
    //printting triangle spaces

    for (int space = 0; space < 2*n-2*row-1; space++)
    {
        cout<<" ";
    }

    //printing right side stars

    for (int star = 0; star < row+1; star++)
    {
        cout<<"*";
    }

    cout<<endl;
    
   }
   return 0;
}