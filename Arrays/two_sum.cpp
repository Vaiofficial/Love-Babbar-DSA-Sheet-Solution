#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3};
    int n = 3;
    int target = 5;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i] << "," << arr[j];
            cout << "  ";
        }
    }

    return 0;
}