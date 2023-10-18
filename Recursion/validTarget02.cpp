#include <bits/stdc++.h>
using namespace std;

void validTarget(int arr[], int size, int index, int target)
{
    if (index >= size)
        return;

    // recursive call

    if (arr[index] == target)
    {
        cout << index << " ";
    }

    validTarget(arr, size, index + 1, target);
}

int main()
{
    int arr[] = {12, 21, 454, 21, 23};
    int size = 5;
    int index = 0;
    int target = 21;

    validTarget(arr, size, index, target);

    return 0;
}