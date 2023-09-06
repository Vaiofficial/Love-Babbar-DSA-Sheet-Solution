#include <bits/stdc++.h>
using namespace std;

int threeSum(int num1 , int num2 , int num3)
{
    int sum  = num1 + num2 + num3;

    return sum;
}

int main()
{
   int a;
   int b;
   int c;

   
    cout<<"Enter the "<<1<<"st"<<" number ";
    cin>>a;

    cout<<"Enter the "<<2<<"nd"<<" number ";
    cin>>b;

    cout<<"Enter the "<<3<<"rd"<<" number ";
    cin>>c;

    int ans = threeSum(a,b,c);
    cout<<"the sum of three number is "<<ans<<endl;

   return 0;
}