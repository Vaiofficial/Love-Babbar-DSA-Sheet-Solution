#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     int n = 3;

//     for (int row = 0; row < n; row++)
//     {
//         for (int col = 0; col < row + 1; col++)
//         {
//             cout << "* ";
//         }
//         cout << endl;
//     }
//     for (int row = 0; row < n - 1; row++)
//     {
//         for (int col = 0; col < n - 1 - row; col++)
//         {
//             cout << "* ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

int main()
{
    int n = 5;
    int cond = 0;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        if (i < n)
            cond = i;

        else
            cond = n - (i % n) - 2;

        for (int i = 0; i <= cond; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}