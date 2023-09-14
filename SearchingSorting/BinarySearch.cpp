#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int n, int target)
{
    int start = 0;
    int end = n - 1;

    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (target == arr[mid])
            return mid;

        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }

        //yaha hum galti karte hai , isko bhul jate hai so isko bhulna nahi hai.update karte jana h mid ko.
        mid = (start + end) / 2;
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 3;
    int n = 10;

    int ans = BinarySearch(arr, n, target);

    if (ans == -1)
    {
        cout << "element is not found" << endl;
    }
    else
    {
        cout << "element is found" << endl;
    }

    return 0;
}