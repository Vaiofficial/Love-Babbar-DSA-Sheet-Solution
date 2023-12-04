#include <bits/stdc++.h>
using namespace std;
#include <deque>
#include <vector>

int sumofminmaxofsubarray(vector<int> &nums, int k)
{
    deque<int> dq, dq1;
    int ans = 0;

    // processing the first window.
    for (int i = 0; i < k; i++) 
    {
        

        // agar ak element greater hai so queue mai se jitne chote hai usse nikaalo
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }

        //viceversa
        while (!dq1.empty() && nums[i]  <= nums[dq1.back()])
        {
            dq1.pop_back();
        }
        // else chote ke index push karo also queue mai se chote ko remove karne k baad
        // maximum jo hai uska index bhi push kardo.
        dq.push_back(i);
        dq1.push_back(i);
    }

    ans += nums[dq.front()] + nums[dq1.front()];

    // processing the remaining window

    for (int i = k; i < nums.size(); i++)
    {
        // remove out of range indexes.
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }

        if (!dq1.empty() && i - dq1.front() >= k)
        {
            dq1.pop_front();
        }
        // remove chote numbers.
        int element = nums[i];

        while (!dq.empty() && element >= nums[dq.back()])
        {
            dq.pop_back();
        }
        while (!dq1.empty() && element <= nums[dq1.back()])
        {
            dq1.pop_back();
        }
        // addition
        dq.push_back(i);
        dq1.push_back(i);

        ans += nums[dq.front()] + nums[dq1.front()];
    }

    return ans;
}

int main()
{

    vector<int>v{2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << sumofminmaxofsubarray(v, k) << endl;

    return 0;
}