#include <bits/stdc++.h>
using namespace std;

int min(int arr[], int size, int minimum)
{
    int mini;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] <= minimum)
            minimum = arr[i];
    }

    return minimum;
}

int main()
{
    int minimum = INT_MAX;
    int arr[10] = {1, 2, 3, 4, 5, -6, 7, 8, 9, 54};
    int size = 10;

    int ans  = min(arr , size , minimum);

    cout<<"the minimum value is :"<<ans;

    return 0;
}