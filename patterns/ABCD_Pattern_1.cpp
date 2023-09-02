#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n =5;

   for (int  row = 0; row < n; row++)
   {
    char ch;
    for (int col = 0; col < row+1; col++)
    {
        int number = col+1;
        ch = number + 'A' - 1;
        cout<<ch;
    }

    for (char alpha = ch; alpha>'A'; )
   {
        alpha = alpha -1;
        cout<<alpha;
   }
   cout<<endl;
   }
   return 0;
}