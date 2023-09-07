#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[20] = {1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
    int oneCount = 0;
    int zeroCount = 0;

    for (int i = 0; i < 20; i++)
    {
        if (arr[i] == 1)
            oneCount++;

        if (arr[i] == 0)
            zeroCount++;
    }

    cout << "the number of zeros are : " << zeroCount;
    cout << endl;
    cout << "the number of ones are : " << oneCount;

    return 0;
}