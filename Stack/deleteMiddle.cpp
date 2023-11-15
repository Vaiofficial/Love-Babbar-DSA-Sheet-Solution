//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    
    void solve(stack<int>&s , int mid)
    {
        //base case
        if(mid==1)
        {
            s.pop();
            return;
        }
        
        //case 1 hum solve karenge and rest recursion karega.
        
        mid--;
        int temp = s.top();
        s.pop();
        
        //recursive call
        solve(s , mid);
        
        //backtracking , mid delete hone ke baad , uske upar ke jo bhi elements the unhe vapas stack mai store karna hoga.
        s.push(temp);
        
        
    }
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int size)
    {
        int mid = 0;
        
        if(size&1)
        {
            mid = size/2 + 1;
        }
        else{
            mid = size/2 + 1;
        }
        
        solve(s , mid);

        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends