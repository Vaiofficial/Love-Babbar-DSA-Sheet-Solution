#include <bits/stdc++.h>
using namespace std;

void pushEven(int arr[], int size, int index, vector<int>&v)
{
    if (index > size)
    {
        return;
    }

    // recursive call

    if (arr[index] % 2 == 0)
    {
        v.push_back(arr[index]);
    }
    pushEven(arr, size, index + 1, v);
}
int main()
{
    int arr[] = {23, 20, 77, 40};
    int size = 4;
    vector<int> v;
    int index = 0;

    pushEven(arr, size, index, v);

    for(auto it : v)
    {
        cout<<it<<" ";
    }
    return 0;
}
