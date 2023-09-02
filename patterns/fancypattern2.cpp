#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n =5;

   for(int row=0;row<n;row++)
   {
        for (int col = 0; col < row+1; col++)
        {
            if(row==0)
            cout<<row+1;

            else if(row==n-1)
            cout<<col+1;

            else
            {
                if(col==1 || col==n-1)
                cout<<col;

                else
                cout<<" ";             
            }
            
        }
        cout<<endl;
        
   }
   return 0;
}