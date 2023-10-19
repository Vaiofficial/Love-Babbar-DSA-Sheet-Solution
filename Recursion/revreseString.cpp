#include <bits/stdc++.h>
using namespace std;

void reverseString(string s, int size, int index)
{
    // base condition.
    if (index >= size)
    {
        return;
    }
    // recursive call.
    reverseString(s, size, index + 1);
    cout << s[index];
}

int main()
{
    string s = "mango";
    int size = 7;
    int index = 0;

    reverseString(s, size, index);
    return 0;
}