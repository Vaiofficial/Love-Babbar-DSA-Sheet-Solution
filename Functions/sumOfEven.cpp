#include <bits/stdc++.h>
using namespace std;

int sumofEvens(int n)
{
    int sum = 0;

    // for (int num = 1; num <=n; num++)
    // {
    //     if (num % 2 == 0)
    //         sum = sum + num;
    // }
    for (int num = 2; num <=n; num+=2)
    {
        sum = sum + num;
    }

    return sum;
}

int main()
{
    int n;

    cout << "Enter the Number :";
    cin >> n;

    // function call
    int ans = sumofEvens(n);
    cout << "The Sum of All Even Numbers is :" << ans;

    // THANKYOU

    return 0;
}