#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;

    //    for(int row=0;row<n;row++)
    //    {
    //     for(int col=0;col<2*row+1;col++)
    //     {
    //         if(col%2!=0)
    //         {
    //             cout<<"*";
    //         }
    //         else{
    //             cout<<row+1;
    //         }
    //     }
    //     cout<<endl;
    //    }

    // ANOTHER SOLUTION WITHOUT USING ANY FORMULA

    for (int row = 0; row < n; row++)
    {
        int lastcol = row + 1;
        for (int col = 0; col < row + 1; col++)
        {
            if (col == lastcol - 1)
                cout << row + 1;

            else
            {
                cout << row + 1 << "*";
            }
        }
        cout << endl;
    }
    // BOTTOM PART OF THE PATTERN

    for (int row = 0; row < n - 1; row++)
    {
        int lastcol = n - 1 - row;
        for (int col = 0; col < n - 1 - row; col++)
        {
            if (col == lastcol - 1)
            {
                cout << n - 1 - row;
            }
            else
                cout << n - 1 - row << "*";
        }
        cout << endl;
    }

    return 0;
}