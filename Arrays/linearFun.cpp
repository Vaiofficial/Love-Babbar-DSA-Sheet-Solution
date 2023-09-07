#include <bits/stdc++.h>
using namespace std;

bool linear(int arr[], int target, int size)
{
    bool flag = 0;

    for (int i = 0; i < size; i++)
    {
        if (target == arr[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 110;
    int size = 10;

    bool ans = linear(arr, target, size);

    if (ans == 1)
        cout << "element is found" << endl;
    else
        cout << "element is not found" << endl;

    return 0;
}