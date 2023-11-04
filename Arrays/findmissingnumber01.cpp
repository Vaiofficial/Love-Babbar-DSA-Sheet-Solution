#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a , vector<int>&ans)
{

    int N = a.size();
    unordered_map<int, int> mp; //time compplexity is high.

    for (auto it : a)
    {
        mp[it]++; // counting frequencies of each element and storing in map.
        if (mp[it] > 1)
        {
            ans.push_back(it);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (mp.find(i)==mp.end())
        {
            ans.push_back(i);
        }
    }

    return ans;
}

int main()
{

    vector<int> a = {1, 2, 1};
    vector<int>ans;
    findMissingRepeatingNumbers(a ,ans);
    cout<<ans.size()<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}