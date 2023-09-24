#include <bits/stdc++.h>
using namespace std;

int divideAnumber(int divisor, int dividend)
{
    int s = 0;
    int e = dividend;
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (mid * divisor == dividend)
        {
            return mid;
        }
        if (mid * divisor < dividend)
        {
            // ans ko store kar rhe hai.
            ans = mid;
            // right mai jao
            s = mid + 1;
        }
        else
        {
            // left mai jao
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int divisor = 7;
    int dividend = 70;

    int quotient = divideAnumber(divisor, dividend);

    cout << "The ans is :" << quotient << endl;

    return 0;
}