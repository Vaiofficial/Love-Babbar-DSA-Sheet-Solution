#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n = 5;

   for(int row=0;row<n;row++)
    {
        for(int star=0;star<row;star++)
        {
            cout<<" ";
        }
        for(int star=0;star<n-row;star++)
        {
            cout<<"* ";
        }
        cout<<endl;

    }

return 0;
}
