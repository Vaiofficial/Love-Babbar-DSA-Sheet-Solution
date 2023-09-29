#include <bits/stdc++.h>
using namespace std;

bool mycompforsecondindex(vector<int> &a , vector<int> &b)
{
   return a[1]<b[1];
}



void printVector(vector<vector<int>>&v)
{

   cout<<"The Values are:"<<endl;
   for(int i=0;i<v.size();i++)
   {
      vector<int>&temp = v[i];
      int a = temp[0];
      int b = temp[1];

      cout<<a<<" "<<b<<endl;
   }   
}

int main()
{
   vector<vector<int>>v;
   cout<<"Enter size of the vector"<<endl;
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
      cout<<"Enter a and b"<<endl;
      int a,b;
      cin>>a>>b;
      vector<int>temp;
      temp.push_back(a);
      temp.push_back(b);
      v.push_back(temp);
   }

   // sort(v.begin() , v.end()); //ye subarray jo hai unke 0th position k base pe karenga sorting.

   sort(v.begin() , v.end() ,mycompforsecondindex); //not it will sort this 2d vector on the basis of 2nd element of subvectors.

   printVector(v);

   return 0;
}