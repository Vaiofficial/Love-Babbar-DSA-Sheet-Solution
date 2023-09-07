#include <bits/stdc++.h>
using namespace std;

int reverse(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int temp;

    while (start <= end)
    {
        if (start == end)
            cout << arr[start] << endl;

        else
        {
            cout << arr[start] << " ";
            cout << arr[end] << " ";
        }

        start++;
        end--;
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    reverse(arr, size);
    return 0;
}