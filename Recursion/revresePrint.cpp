#include <bits/stdc++.h>
using namespace std;

void reversePrint(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    reversePrint(n - 1);
}

int main()
{
    int n;
    cout << "Enter the Number -";
    cin >> n;

    reversePrint(n);

    return 0;
}