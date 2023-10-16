#include <bits/stdc++.h>
using namespace std;

void solve(int *&p) //here iam using pass by reference.
{
    p = p + 1;
}

int main()
{
    int a = 5;
    int *p = &a;

    cout << p << endl;
    cout << &p << endl;
    cout << *p << endl;

    solve(p);
    cout << endl;

    cout << p << endl;
    cout << &p << endl;
    cout << *p << endl;
    return 0;
}