#include <bits/stdc++.h>
using namespace std;

void findDigits(int number, vector<int> &v)
{
    if (number == 0)
    {
        return;
    }
    int rem = number % 10;
    findDigits(number / 10, v);
    v.push_back(rem); // iska ulta print karna hai to isko function call ke upar kardo.
}
int main()
{
    int number = 4215;
    vector<int> v;

    findDigits(number, v);

    for (auto it : v)
    {
        cout << it << " ";
    }

    return 0;
}