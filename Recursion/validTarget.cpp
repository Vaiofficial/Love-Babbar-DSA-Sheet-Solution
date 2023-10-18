#include <bits/stdc++.h>
using namespace std;

bool validTarget(int arr[], int size, int index, int target)
{
    if (index >= size)
        return false;

    // recursive call

    if (arr[index] == target)
    {
        return true;
    }

    validTarget(arr, size, index + 1, target);
}

int main()
{
    int arr[] = {12, 21, 454, 12, 23};
    int size = 5;
    int index = 0;
    int target = 12;

    bool ans = validTarget(arr, size, index, target);

    if (ans == true)
        cout << "The target is valid" << endl;
    else
        cout << "The target is not valid" << endl;
    return 0;
}