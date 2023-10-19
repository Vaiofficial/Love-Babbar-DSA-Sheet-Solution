#include <bits/stdc++.h>
using namespace std;

bool sortedCheck(int arr[], int size, int index)
{
    if (index >= size)
    {
        return true;
    }
    else if (arr[index] > arr[index - 1])
    {
        sortedCheck(arr, size, index + 1);
    }
    else
    {
        return false;
    }

    // recursive call
}

int main()
{
    int arr[] = {1, 7, 3, 4, 5};
    int size = 5;
    int index = 1;

    bool ans = sortedCheck(arr, size, index);

    if (ans == true)
    {
        cout << "The array is sorted" << endl;
    }
    else
    {
        cout << "The array is not sorted" << endl;
    }
    return 0;
}