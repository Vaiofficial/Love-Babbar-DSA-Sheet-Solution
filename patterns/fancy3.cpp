#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n = 5;

   for (int row = 0; row < n; row++)
   {
        for(int left = 0; left < 2*n-2-row; left++)
        {
            cout<<"*";
        }
        for(int star = 0; star < 2*row+1; star++)
        {   
            if(star%2==0)
            cout<<row+1;

            else
            cout<<"*";
        }
        for(int right = 0; right< 2*n-2-row; right++)
        {
            cout<<"*";
        }
        cout<<endl;
   }
   
   return 0;
}