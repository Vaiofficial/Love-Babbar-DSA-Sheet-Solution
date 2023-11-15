#include <bits/stdc++.h>
#include<stack>
using namespace std;


int main()
{
   string name = "vaibhav";
   stack<char>st;

   for(int i=0;i<name.size();i++)
   {
        char ch = name[i];
        st.push(ch);   
   }

   while (!st.empty())
   {
        cout<<st.top();
        st.pop();
   }
   
   return 0;
}