#include <bits/stdc++.h>
using namespace std;

int powerFind(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }

    int recurCall = n * powerFind(n, p - 1);

    return recurCall;
}

int main()
{
    int n, p;
    cout << "Enter the base number :-";
    cin >> n;
    cout << "Enter the Power:-";
    cin >> p;

    int totalValue = powerFind(n, p);
    cout << "The power of the number is :" << totalValue << endl;
    return 0;
}