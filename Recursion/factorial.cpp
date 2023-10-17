#include <bits/stdc++.h>
using namespace std;

int factorialFinding(int n)
{
    // this is our base condtion.
    if (n == 1 || n == 0)
    {
        return 1;
    }
    // this is our recursive call
    int recurAns = n * factorialFinding(n - 1);

    return recurAns;
}

int main()
{
    int n;
    cout << "enter the number" << endl;
    cin >> n;

    int ans = factorialFinding(n);

    cout << "the factorial of the number " << n << " is : " << ans << endl;
    return 0;
}