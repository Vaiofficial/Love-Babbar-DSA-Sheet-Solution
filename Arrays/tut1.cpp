#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
        // cout<<endl;
    }
    cout << endl;
    cout << "the array after doubling up" << endl;

    // doubling up each value of the array of size 10
    for (int i = 0; i < 10; i++)
    {
        arr[i] = arr[i] * 2;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}