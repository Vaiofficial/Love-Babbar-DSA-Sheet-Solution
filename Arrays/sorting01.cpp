#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0};
    int n = 15;
    int zeroCount = 0;
    int oneCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zeroCount++;
        }
        else
        {
            oneCount++;
        }
    }
    cout << "zeroCount is:" << zeroCount << endl;
    cout << "zeroCount is:" << oneCount << endl;

    int index = 0;

    while (zeroCount--)
    {
        arr[index] = 0;
        index++;
    }

    while (oneCount--)
    {
        arr[index] = 1;
        index++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}