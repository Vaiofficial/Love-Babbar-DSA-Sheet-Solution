#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 7;

    int count = 0;

    while (n > 0)
    {
        int bit = n % 2;
        if (bit == 1)
        {
            count++;
        }
        n = n / 2;
    }
    cout << count << endl;
    return 0;
}