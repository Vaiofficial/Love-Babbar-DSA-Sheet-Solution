#include <bits/stdc++.h>
using namespace std;

bool nearlySorted(int arr[], int n, int target)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (target == arr[mid])
            return true;

        if (mid -1>=0 && target == arr[mid - 1])
            return true;

        if (target == arr[mid + 1])
            return true;

        else if (target > arr[mid])
            s = mid + 2;

        else if (target < arr[mid])
            e = mid - 2;

        mid = s + (e - s) / 2;
    }

    return false;
}

int main()
{
    int arr[] = {20, 10, 30, 50, 40, 70, 60};
    int n = sizeof(arr) / sizeof(int);
    int target = 20;

    int found = nearlySorted(arr, n, target);

    if (found == 1)
        cout << "The Number is Found" << endl;
    else
    {
        cout << "The Number is Not Found" << endl;
    }

    return 0;
}