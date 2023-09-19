#include <bits/stdc++.h>
using namespace std;

double sqrt(float x)
{
    int s = 0;
    int e = x;
    double mid = s + (e - s) / (float)2;
    double ans = 0;

    while (s <= e)
    {
        // check kar rha ki mid hi to answer nahi hai agr hai to return kardo bhai.
        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid * mid < x)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{

    long long int num = 1234123312341;

    float ans = sqrt(num);
    cout << "the exact square root is :" << ans << endl;

    return 0;
}