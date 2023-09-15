// DUTCH NATIONAL FLAG ALGORITHM

// T.C = O(n)
// S.C = O(1)

#include <bits/stdc++.h>
using namespace std;

void negativeOneSide(int arr[], int n)
{
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        if (arr[low] < 0) // worst case jab sare elements negative hogi tab low increment hote chale jygaa until low<high
        {
            low++;
        }
        else if (arr[high] > 0)
        {
            high--;
        }
        else
        {
            swap(arr[low], arr[high]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 2, -4, 6, -7, 9, -19, 32};
    int n = sizeof(arr) / sizeof(int);

    negativeOneSide(arr, n);

    return 0;
}