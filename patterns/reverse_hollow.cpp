#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n = 4;

   for(int row=0;row<n;row++)
   {
    for(int space=0;space<row;space++)
    {
        cout<<" ";
    }
    for(int star =0;star<n-row;star++)
    {
        if(star==0 || star==n-row-1)
        {
            cout<<"* ";
        }
        else{
            cout<<"  ";
        }
    }
    cout<<endl;
   }
   return 0;
}