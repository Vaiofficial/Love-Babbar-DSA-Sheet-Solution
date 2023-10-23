#include <bits/stdc++.h>
using namespace std;

void subsequence(string s)
{
    int num_subs = pow(2, s.size());
    for (int n = 0; n < num_subs; n++)
    {
        string out;
        int num = n;

        int i = 0;
        while (num)
        {
            int b = (num & 1);
            if (b)
            {
                out.push_back(s[i]);
            }
            ++i;
            num >>=1;
        }

        cout << out << endl;
    }
}

int main()
{
    string s = "abc";
    string output;
    int index = 0;

    subsequence(s);
    return 0;
}