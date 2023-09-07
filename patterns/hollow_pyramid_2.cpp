#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < row + 1; col++)
        {
            // the last col of each row

            int lastCol = row + 1 - 1;

            if (row == 0 || row == n - 1)
            {
                cout << col + 1 << " ";
            }
            else
            {
                if (col == 0 || col == lastCol)
                    cout << col + 1 << " ";

                else
                    cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}