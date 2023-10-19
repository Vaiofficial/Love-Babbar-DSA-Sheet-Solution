#include <bits/stdc++.h>
using namespace std;

void subsequenceFind(string s, string output, int index)
{
    if (index >= s.size())
    {
        cout << "->" << output << endl;
        return;
    }

    // include
    char ch = s[index];

    output.push_back(ch);
    subsequenceFind(s, output, index+1);

    // exclude
    output.pop_back();
    subsequenceFind(s, output, index+1);
}

int main()
{
    string s = "xy";
    string output = "";
    int index = 0;

    subsequenceFind(s, output, index);

    return 0;
}