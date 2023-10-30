#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, vector<int> &temp, int start, int mid, int end)
{
    int i = start, j = mid + 1;

    //first array - start to mid 
    //second array - mid+1 to end
    //merged array - start to end.
    int k = start;

    while (i <= mid && j <= end)
    {
        if (v[i] <= v[j])
        {
            temp[k++] = v[i++];
        }
        else
        {
            temp[k++] = v[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = v[i++];
    }
    while (j <= end)
    {
        temp[k++] = v[j++];
    }

    while (start <= end)
    {
        v[start] = temp[start];
        ++start;
    }
}
void mergeSort(vector<int> &v, vector<int> &temp, int start, int end)
{
    if(start>=end)
    {
        return;
    }

    int mid = (start + end)/2;
    mergeSort(v, temp, start, mid);
    mergeSort(v, temp, mid + 1, end);
    merge(v, temp, start, mid, end);
}

int main()
{
    vector<int> v{4, 3, 1, 7, 9, 2};
    vector<int> temp(v.size(), 0);
    mergeSort(v, temp, 0, v.size() - 1);

    for (int i = 0; i < v.size(); i++)
    {
        cout << temp[i] << " ";
    }

    return 0;
}