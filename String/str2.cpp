#include <bits/stdc++.h>
using namespace std;

bool palindromeCheck(char ch[], int len)
{
    int i = 0;
    int j = len - 1;

    while (i <= j)
    {
        if (ch[i] == ch[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char ch[100];

    cout << "enter to search palindrome" << endl;
    cin.getline(ch, 100);
    int len = strlen(ch);

    if (palindromeCheck(ch, len))
        cout << "its is a palindrome" << endl;
    else
        cout << "it is not a palindrome" << endl;

    return 0;
}