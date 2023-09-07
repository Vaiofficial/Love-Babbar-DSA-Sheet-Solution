#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    int count = 1;
    // growing phase
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col <= row; col++)
        {
            cout << count;
            count++;
            if (col < row)
                cout << "*";
        }
        cout << endl;
    }

    // srinking phase
    int start = count - n;
    for (int row = 0; row < n; row++)
    {
        int k = start;
        for (int col = 0; col <= n - row - 1; col++)
        {
            cout << k;
            k++;
            if (col < n - row - 1)
                cout << "*";
        }
        start = start - (n - row - 1);
        cout << endl;
    }

    return 0;
}