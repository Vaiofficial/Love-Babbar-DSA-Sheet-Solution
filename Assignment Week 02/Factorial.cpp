#include <bits/stdc++.h>
using namespace std;

int Fact(int num)
{
    int fact = 1;

    while (num >= 1)
    {
        fact = fact * num;
        num--;
    }

    return fact;
}

int main()
{
    int num;
    cout << "Enter a Number: ";
    cin >> num;

    int ans = Fact(num);

    cout << "the Factorial of the number is: " << ans;

    return 0;
}