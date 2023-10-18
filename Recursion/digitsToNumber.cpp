#include <bits/stdc++.h>
using namespace std;

void digitToNumber(vector<int> v, int size, int index, int places, int &ans)
{
    if (index >= size)
    {
        return;
    }
    ans = ans + v[index] * places;
    digitToNumber(v, size, index + 1, places / 10, ans);
}

int main()
{
    vector<int> v{1, 2, 4, 7};
    int size = 4;
    int index = 0;
    int places = 1000;
    int ans = 0;

    digitToNumber(v, size, index, places, ans);

    cout << ans<<endl;
    cout<<"size of ans is : "<<sizeof(int);

    return 0;
}