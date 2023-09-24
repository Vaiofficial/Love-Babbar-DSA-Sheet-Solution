#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    int count = 0;

    while (n > 0) //we can also use while(n) , last mai 0 hoga to false ho jyga aur loop exit.
    {
        int bit = n & 1;
        if (bit == 1) //here we can also use the condition if(bit).
        {
            count++;
        }
        n = n >> 1; //n>>=1
    }

    cout << count << endl;

    return 0;
}