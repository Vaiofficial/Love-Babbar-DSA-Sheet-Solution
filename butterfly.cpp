#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 15;

    for (int row = 0; row < n; row++)
    {
        // topleft
        for (int col = 0; col < row + 1; col++)
        {
            cout << "* ";
        }

        // topmid
        for (int space = 0; space < 2 * n - 2 * row - 2; space++)
        {
            cout << "  ";
        }

        // topright
        for (int col = 0; col < row + 1; col++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    // startinf row of bottom side
    for (int row = 0; row < n; row++)
    {

        // bottom left
        for (int col = 0; col < n - row; col++)
        {
            cout << "* ";
        }

        // bottom mid

        for (int space = 0; space < 2 * row; space++)
        {
            cout << "  ";
        }

        // bottom right
        for (int col = 0; col < n - row; col++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}