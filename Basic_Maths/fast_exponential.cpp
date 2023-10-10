#include <bits/stdc++.h>
using namespace std;

int powerBasic(int a, int b)
{
    int ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans = ans * a;
    }
    return ans;
}

int powerFast(int a , int b)
{
    int ans = 1;
    while(b>0)
    {
        if(b&1)
        {
            ans  = ans*a;
        }
        a = a * a;
        b>>=1;
    }
    return ans;  
}

int main()
{
    cout <<powerBasic(2, 3) << endl;
    cout <<powerFast(2, 4) << endl;

    return 0;
}