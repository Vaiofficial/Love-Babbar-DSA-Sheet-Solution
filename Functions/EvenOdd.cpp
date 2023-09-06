#include <bits/stdc++.h>
using namespace std;

int EvenOdd(int num)
{
   if(num%2==0)
   cout<<"The Number is a Even Number"<<endl;

   else{
      cout<<"The Number is not a Even Number"<<endl;
   }
}

int main()
{
   int n;

   cout<<"Enter the Number :";
   cin>>n;

   EvenOdd(n);

   return 0;
}