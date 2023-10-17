#include <bits/stdc++.h>
using namespace std;

int fibonacciFind(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    int ans = fibonacciFind(n - 1) + fibonacciFind(n - 2);

    return ans;
}

int main()
{
    int n;
    cout << "Enter the number" << endl;
    cin >> n;

    int ans = fibonacciFind(n);
    cout << ans << " ";
    return 0;
}