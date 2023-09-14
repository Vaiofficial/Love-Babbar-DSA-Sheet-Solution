#include <bits/stdc++.h>
using namespace std;

int firstOccurence(int arr[], int n, int target)
{
    int start = 0;
    int end = n - 1;
    int ans = -1;

    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (target == arr[mid])
        {
            ans = mid;
            start = mid + 1;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }

        // yaha hum galti karte hai , isko bhul jate hai so isko bhulna nahi hai.update karte jana h mid ko.
        mid = (start + end) / 2;
    }

    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 5, 5, 6, 9, 10};
    int target = 5;
    int n = 10;

    int ans = firstOccurence(arr, n, target);

    cout << "The first occuerence of the element is at index: " << ans;

    return 0;
}