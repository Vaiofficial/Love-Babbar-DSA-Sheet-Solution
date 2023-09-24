#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool isPossibleHeight(vector<long long int> &trees, long long int m , long long int mid)
{
    long long int woodCollect = 0;

    for(int i=0;i<trees.size();i++)
    {
        if(trees[i]>mid)
        {
            woodCollect += trees[i] - mid;
        }
    }

    return woodCollect>=m;
}

long long int sawBladePossibleHeight(vector<long long int> &trees, long long int m)
{
    long long int start = 0, ans = -1;
    long long int end = *max_element(trees.begin(), trees.end()); //#include<algorithm> to use this.

    while (start <= end)
    { 
        long long int mid = start + (end - start) / 2;

        if (isPossibleHeight(trees, m, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    long long int m, n;

    cin >> n >> m;

    vector<long long int> trees;

    while (n--)
    {
        long long int height;
        cin >> height;
        trees.push_back(height);
    }

    cout<<sawBladePossibleHeight(trees, m);

    return 0;
}