#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int temp = arr[n - 1];
    int current = n - 1;

    while (current >= 0)
    {
        arr[current] = arr[current-1];
        current--;   
    }

    arr[0] = temp;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}