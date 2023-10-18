#include <bits/stdc++.h>
using namespace std;

void findMax(int arr[], int size, int index, int &maxi)
{
    if (index > size)
    {
        return;
    }

    if (arr[index] > maxi)
    {
        maxi = arr[index];
    }

    findMax(arr, size, index + 1, maxi);
}

int main()
{
    int arr[] = {22, 444, 12, 1, 897, 567};
    int size = 6;
    int index = 0;
    int maxi = INT_MIN;

    findMax(arr, size, index, maxi);

    cout << "the maximum element is :-" << maxi << endl;

    return 0;
}