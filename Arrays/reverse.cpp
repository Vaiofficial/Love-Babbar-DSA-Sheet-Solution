#include <bits/stdc++.h>
using namespace std;

int reverse(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int temp;

    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    reverse(arr , size);
    return 0;
}