#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n - row; col++)
        {
            int lastcol = n - row;

            if (row == 0 || row == n - row - 1)
                cout << col + 1 << " ";
            // for printing stars just replace col+1 with *
            else
            {
                if (col == 0 || col == lastcol - 1)
                    cout << col + 1 << " ";

                else
                {
                    cout << "  ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}