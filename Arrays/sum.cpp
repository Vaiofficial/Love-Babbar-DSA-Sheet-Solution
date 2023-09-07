#include <bits/stdc++.h>
using namespace std;

int main()
{
   int sum = 0;
   int arr[5];

   for (int i = 0; i < 5; i++)
   {
    cin>>arr[i];
   }

   for (int i = 0; i < 5; i++)
   {
    sum = sum + arr[i];
   }
   
   cout<<endl;
   cout<<"the sum is :"<<sum;


   
   return 0;
}