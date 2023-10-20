#include <bits/stdc++.h>
using namespace std;

bool palindromeCheck(string &s, int i, int j)
{
    if (i >= j)
    {
        return true;
    }

    if (s[i] != s[j])
    {
        return false;
    }

    return palindromeCheck(s, i + 1, j - 1);
}

int main()
{
    string s = "totot"; // nitin
    int size = 5;
    int i = 0;
    int j = size - 1;

    bool ans = palindromeCheck(s, i, j);

    if (ans == true)
        cout << "String is palindrome" << endl;

    else
        cout << "String is not a palindrome" << endl;

    return 0;
}