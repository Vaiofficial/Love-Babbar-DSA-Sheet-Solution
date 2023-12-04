#include <bits/stdc++.h>
using namespace std;

void negativeWindow(int *arr, int n, int k)
{
    deque<int> dq;

    // first window ko process , usme se negative number ke index extract kar diye and push queue mai.
    for (int i = 0; i < k; i++)
    {
        int element = arr[i];
        if (arr[i] < 0)
        {
            dq.push_back(i);
    }
        }

    // now process remaining windows

    for (int i = k; i < n; i++)
    {
        if (dq.empty())
        {
            cout << "0" << endl;
        }
        else
        {
            cout << arr[dq.front()] << " ";
        }

        // removal of index from the queue if it is not lie inside current window.
        if (i - dq.front() >= k) //ye formula se pta chal jyda ki queue mai jo index hai vo window k out of bound hai ya nahi.
        {
            dq.pop_front();
        }
        // addition if num is negative
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }

    if (dq.empty())
    {
        cout << "0" << endl;
    }
    else
    {
        cout << arr[dq.front()] << " ";
    }
}

int main()
{
    int arr[] = {2, -5, 4, -1, -2, 6, 5};
    negativeWindow(arr, 7, 3);

    return 0;
}