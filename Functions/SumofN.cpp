#include <bits/stdc++.h>
using namespace std;

int SumofN(int num)
{
    int sum = 0;

    for (int i = 1; i <=num; i++)
    {
        sum = sum + i;
    }
    return sum;
}

int main()
{
    int n;

    cout << "Enter a Number :";
    cin >> n;

    int ans = SumofN(n);
    cout << "the sum of n Numbers is :" <<ans;

    return 0;
}