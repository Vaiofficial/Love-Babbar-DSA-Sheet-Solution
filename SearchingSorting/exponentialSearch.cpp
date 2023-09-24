#include <bits/stdc++.h>
using namespace std;

int bs(int arr[], int start, int end, int target)
{
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (arr[mid] == target)
            return mid;

        else if (target > arr[mid])
            start = mid + 1;

        else
        {
            end = mid - 1;
        }

        mid = (start + end) / 2;
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int target)
{
    int i = 1;

    // corner case
    if (arr[0] == target)
        return 0;

    while (i < n && arr[i] <= target)
    {
        // incremnenting exponential times.
        i = i * 2;
    }
    // returning binary search function which is written above.
    return bs(arr, i / 2, min(i, n - 1), target);
}

int main() 
{
    int arr[] = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int n = 10;
    int target = 11;

    int ansIndex = exponentialSearch(arr, n, target);

    cout << "The target element is present at index : " << ansIndex << endl;
    return 0;
}