#include <bits/stdc++.h>
using namespace std;

int firstOccurence(int arr[], int n)
{
    int start = 0;
    int end = n;
    int ans = -1;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        int diff = arr[mid] - mid;

        if (diff == 1)
        {
            // agr 1 hai to right mai shift karenge
            start = mid + 1;
        }
        else
        {
            ans = mid;
            // left mai shift karenge
            end = mid - 1;
        }

        // ye bhulna nahi hai bilkul , mid ko update karna hai hamesha
        mid = start + (end - start) / 2;
    }

    // if(ans+1==0)
    // {
    //     return n+1;
    // }

    return ans + 1;
}

int main()
{
    int arr[] = {1, 2,3, 4, 5, 6,7, 8, 9};
    // int target = 5;
    int n = 9;

    int ans = firstOccurence(arr, n);

    cout << "missing element is " << ans;

    return 0;
}