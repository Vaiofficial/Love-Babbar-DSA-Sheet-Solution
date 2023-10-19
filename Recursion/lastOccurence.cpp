#include <bits/stdc++.h>
using namespace std;

void findLastOccurence(string s, int size, int index, int &ans, char target)
{
    if (index > size)
    {
        return;
    }

    if (s[index] == target)
    {
        ans = index;
    }
    findLastOccurence(s, size, index + 1, ans, target);
}

int main()
{
    string s = "abcbdaiu";
    int size = s.size();
    int index = 0;
    char target = 'b';
    int ans;

    findLastOccurence(s, size, index, ans, target);

    cout << "The last element at the index : " << ans << endl;
    return 0;
}