#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int start, int end, int target)
{

    if (start > end)
    {
        return -1;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    if (arr[mid] < target) // right
    {
        return binarySearch(arr, mid + 1, end, target);
    }
    else // left
    {
        return binarySearch(arr, start, mid - 1, target);
    }
}
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 6, 2};
    int size = 7;
    int start = 0;
    int end = size - 1;
    int target = 9;

    int ans = binarySearch(arr, start, end, target);

    if (ans != -1)
        cout << "The element is found at index :" << ans << endl;
    else
        cout << "The element is not found" << endl;

    return 0;
}