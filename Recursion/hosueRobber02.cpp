#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> nums, int s, int e)
{
    if (s > e)
    {
        return 0;
    }

    int option1 = nums[s] + solve(nums, s + 2, e);
    int option2 = 0 + solve(nums, s + 1, e);

    int finalAns = max(option1, option2);

    return finalAns;
}

int main()
{
    vector<int> nums{1 , 2, 3, 1 , 3 ,8 , 9};
    int size = nums.size();

    if (size == 1)//yaha pass galti hogi so yaad rakhana.
    {
        return nums[0];
    }
    int option1 = solve(nums, 0, size - 2);
    cout<<option1<<endl;
    int option2 = solve(nums, 1, size - 1);
    cout<<option2<<endl;
    int ans = max(option1, option2);

    cout << ans << endl;

    return 0;
}