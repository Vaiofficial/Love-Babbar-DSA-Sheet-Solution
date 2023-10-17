#include <bits/stdc++.h>
using namespace std;

int sumFind(int n)
{
    if (n == 1)
    {
        return 1;
    }

    int sum = n + sumFind(n - 1);

    return sum;
}

int main()
{
    int n;
    cout << "Enter the number :-";
    cin >> n;

    int ans = sumFind(n);

    cout << "The sum is :-" << ans;

    return 0;
}