#include <bits/stdc++.h>
using namespace std;

int paintingFence(int n, int k)
{
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return k + k * (k - 1); // here k for same case and k * (k+1) for different case.
    }

    int ans = (k - 1) * (paintingFence(n - 1, k) + paintingFence(n - 2, k));
    return ans;
}

int main()
{
    int n = 2;
    int k = 4;
    int ans = paintingFence(n, k);
    cout << ans;
    return 0;
}