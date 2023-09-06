#include <bits/stdc++.h>
using namespace std;

int Prime(int num)
{
    //number prime hoga jab vo bas khud se ya phir 1 se divide hoga means total 2 baar divide hoga.
    int count =0;

    // for (int i = 1; i <= num; i++)
    // {
    //     if(num%i==0)
    //     count++;
    // }
    // if(count == 2)
    // cout<<"the number is a prime number"<<endl;

    // else
    // cout<<"the number is not a prime number"<<endl;

    for (int i = 2; i <num; i++)
    {
        if(num%i==0)
        return false;
    }
    return true;
    
}

int main()
{
   int n;

   cout<<"Enter the Number :";
   cin>>n;

   bool ans = Prime(n);
   
   if(ans==true)
   cout<<"its a prime number"<<endl;

   else{
    cout<<"its not a prime number"<<endl;
   }
   
   return 0;
}