#include <bits/stdc++.h>
using namespace std;

int colSum(int arr[][3], int row, int col)
{
    int sum = 0;
    for (int i = 0; i < col; i++)
    {

        sum = sum + arr[i][i];
    }
    return sum;
}

int main()
{
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int row = 3;
    int col = 3;

    int ans = colSum(arr, row, col);

    cout << "The Sum is :" << ans;

    return 0;
}