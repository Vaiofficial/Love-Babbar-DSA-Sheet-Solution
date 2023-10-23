#include <bits/stdc++.h>
using namespace std;

void removeOccurence(string &s, string part) // TIME COMPLEXITY - O(N*M) //SPACE COMPLEXITY - O(N/M)(WORST MAI , JAB BAAR BAAR PART STRING AAYE MAIN STRING KE ANDAR AND BAAR BAAR RECURSIVE CALL HO.)
{
    int found = s.find(part);
    if (found != string::npos)
    {
        string left = s.substr(0, found);
        string right = s.substr(found + part.size(), s.size());
        s = left + right;

        removeOccurence(s, part);
    }
    else
    {
        return;
    }
}

int main()
{
    string s;
    cin >> s;
    string part;
    cin >> part;

    removeOccurence(s, part);

    cout << "The string after removing all the occurence of part string is :-" << endl;
    cout << s << endl;

    return 0;
}