#include <bits/stdc++.h>
using namespace std;

void permutation(string &s, int index)
{
    if (index >= s.size())
    {
        cout << s << " ";
        return;
    }

    for (int j = index; j < s.size(); j++)
    { 
        swap(s[index], s[j]);
        // recursion call
        permutation(s, index + 1);
        // backtracking
        swap(s[index], s[j]); // by reference pass kiye hai so directly string mai changes honge so jab j =1 and j = 2 hoga to vha original string nahi jyga , vha vo changes or swapped string pass hoga so therefore ans bhi wrong aayga.
    }
}

int main()
{
    string s = "abc";
    int index = 0;

    permutation(s, index);
    return 0;
}