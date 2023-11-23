#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int>&q, int k)
{

    stack<int> st;

    for (int i = 0; i < k; i++)
    {
        int element = q.front();
        q.pop();
        st.push(element);
    }

    while (!st.empty())
    {
        int element = st.top();
        st.pop();
        q.push(element);
    }

    for (int i = 0; i < (q.size() - k); i++)
    {
        int element = q.front();
        q.pop();
        q.push(element);
    }

    return q;
}

int main()
{

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    modifyQueue(q, 3);

    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        cout << element << " ";
    }

    return 0;
}