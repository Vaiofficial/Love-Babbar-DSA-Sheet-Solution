#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n = 5;

   for (int row = 0; row < n; row++)
   {
        for (int col = 0; col < row+1; col++)
        {
            cout<<col+1<<" ";
        }
        cout<<endl;
            
   }
   
   return 0;
}