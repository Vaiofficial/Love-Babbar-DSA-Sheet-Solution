#include <bits/stdc++.h>
using namespace std;

void doubleElement(int arr[], int size, int index)
{
    if (index > size)
        return;

    // recursive call

    int ans = arr[index] * 2;
    arr[index] = ans;

    doubleElement(arr, size, index + 1);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    int index = 0;

    doubleElement(arr, size, index);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}