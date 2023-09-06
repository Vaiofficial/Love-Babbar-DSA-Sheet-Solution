#include <bits/stdc++.h>
using namespace std;

void Counting(int n);

int main()
{
   int n;

   cout<<"Enter a Number :";
   cin>>n;

   Counting(n);

   return 0;
}

void Counting(int n){

    for (int i = 1; i <= n; i++)
    {
        cout<<i<<" ";
    }
    
}