//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void solve(stack<int>&s , int x)
    {
        
        if(s.empty())
        {
            s.push(x);
            return;
        }
        
        //we will solve one case and rest will be taken care by the recursion.
        int temp = s.top();
        s.pop();
        
        //recursion call
        solve(s , x);
        
        //backtracking
        s.push(temp);
        
    }

    stack<int> insertAtBottom(stack<int>s,int x){
        
        solve(s , x);
        return s;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        cin>>x;
        stack<int> st;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            st.push(a);
        }
        Solution ob;
        stack<int> tmp=ob.insertAtBottom(st,x);
        vector<int> v;
        while(tmp.size()){
            v.push_back(tmp.top());tmp.pop();
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            if(i!=v.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends