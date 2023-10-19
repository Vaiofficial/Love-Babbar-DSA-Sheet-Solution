#include <bits/stdc++.h>
using namespace std;

void reverseString(string name, int start, int end)
{
    if (start == end)
    {
        cout << name;
        return;
    }

    swap(name[start], name[end]);
    reverseString(name, start + 1, end - 1);
}

int main()
{
    string name = "nnnnmmmm";
    int size = 7;
    int start = 0;
    int end = size - 1;

    reverseString(name, start, end);
    return 0;
}