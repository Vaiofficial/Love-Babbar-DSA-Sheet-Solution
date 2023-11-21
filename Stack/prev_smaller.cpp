#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(int *arr, int size, vector<int> &ans)
{
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < size; i++)
    {
        int curr = arr[i];

        while (st.top() >= curr)
        {
            st.pop();
        }

        ans[i] = st.top(); // so before pushing element into the stack hum vector mai stack ke top ko store and update kar rhe hai , so that we can return our ans as a vector.
        st.push(curr);
    }

    return ans;
}

int main()
{
    int arr[] = {8, 4, 6, 2, 3};
    int size = 5;
    vector<int> ans(size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    prevSmaller(arr, size, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}