#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n =4;

   for(int row=0;row<n;row++)
   {
    for(int col=0;col<n-row-1;col++)
    {
        cout<<" ";
    }

    for(int star=0;star<row+1;star++)
    {   
        //print star for first and last column only
        if(star==0 || star==row+1-1)
        cout<<"* ";

        else{
            cout<<"  ";
        }
    }
    cout<<endl;
   }

   return 0;
}