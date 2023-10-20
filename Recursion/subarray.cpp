#include <bits/stdc++.h>
using namespace std;

void subarrayUtil(vector<int> &arr, int start, int end)
{
    if (end == arr.size())
    {
        return;
    }

    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    subarrayUtil(arr, start, end + 1);
}

void subarrayPrint(vector<int> &arr)
{
    for (int start = 0; start < arr.size(); start++)
    {
        int end = start;
        subarrayUtil(arr, start, end);
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    subarrayPrint(arr);
    return 0;
}