#include <bits/stdc++.h>
using namespace std;

bool maxElement(int arr[][3], int row, int col)
{

    int maxAns = INT_MIN;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] > maxAns)
            {
                maxAns = arr[i][j];
            }
        }
    }

    return maxAns;
}

int main()
{
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int row = 3;
    int col = 3;

    int ans = maxElement(arr, row, col);

    cout << "max element is :" << ans;

    return 0;
}