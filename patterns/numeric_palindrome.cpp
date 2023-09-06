#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;

    for (int row = 0; row < n; row++)
    {
        for (int space = 0; space < n - row - 1; space++)
        {
            cout << " ";
        }
        for (int star = 0; star < row + 1; star++)
        {
            cout << star + 1 << "";
        }
        if (row > 0)
        {
            for (int star = row; star > 0; star--)
            {
                cout << star << "";
            }
        }

        cout << endl;
    }

    return 0;
}