#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < row; col++)
        {
            cout << "  ";
        }
        for (int star = 0; star < 2 * n - 2 * row - 1; star++)
        {
            int last = 2*n-2*row-1-1;

            if(star==0||star==last)
            cout << "* ";
            else
            cout<<"  ";
        }
        cout << endl;
    }

    return 0;
}