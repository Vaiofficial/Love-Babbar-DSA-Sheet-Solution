#include <bits/stdc++.h>
using namespace std;

// USING RECURSION

void reverse(queue<int> &q)
{
    // base case
    if (q.empty())
    {
        return;
    }

    // recursive call

    int element = q.front();
    q.pop();

    reverse(q);

    q.push(element);
}

// USING STACK METHOD 01
void reverseQueue(queue<int> &q)
{
    stack<int> st;

    // queue se lo aur stack mai push karo
    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        st.push(element);
    }
    // stack le lo aur queue mai push karo
    while (!st.empty())
    {
        int element = st.top();
        st.pop();
        q.push(element);
    }
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    // cout << "Before Reversal :";
    // while (!q.empty())
    // {
    //     int element = q.front();
    //     q.pop();
    //     cout << element<< " ";
    // }
 
    reverse(q);      // recursion method call
    reverseQueue(q); // stack method call

    cout << endl
         << "After Reversal :";

    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        cout << element << " ";
    }

    return 0;
}